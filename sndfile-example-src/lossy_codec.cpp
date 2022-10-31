#include <iostream>
#include <fstream>
#include <string>
#include <sndfile.hh>
#include <fftw3.h>
#include "bitstream.h"
#include "wav_quant.h"


using namespace std;


int main(int argc, char const *argv[])
{
    bool verbose { false };
	size_t bs { 1024 };
	double dctFrac { 0.2 };

	if(argc < 3) {
		cerr << "Usage: wav_dct [ -v (verbose) ]\n";
		cerr << "               [ -bs blockSize (def 1024) ]\n";
		cerr << "               [ -frac dctFraction (def 0.2) ]\n";
		cerr << "               wavFileIn wavFileOut\n";
		return 1;
	}

	for(int n = 1 ; n < argc ; n++)
		if(string(argv[n]) == "-v") {
			verbose = true;
			break;
		}


	SndfileHandle sfhIn { argv[argc-2] };
	if(sfhIn.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

	if((sfhIn.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) {
		cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if((sfhIn.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

	SndfileHandle sfhOut { argv[argc-1], SFM_WRITE, sfhIn.format(),
	  sfhIn.channels(), sfhIn.samplerate() };
	if(sfhOut.error()) {
		cerr << "Error: invalid output file\n";
		return 1;
    }

	if(verbose) {
		cout << "Input file has:\n";
		cout << '\t' << sfhIn.frames() << " frames\n";
		cout << '\t' << sfhIn.samplerate() << " samples per second\n";
		cout << '\t' << sfhIn.channels() << " channels\n";
	}

	size_t nChannels { static_cast<size_t>(sfhIn.channels()) };
	size_t nFrames { static_cast<size_t>(sfhIn.frames()) };

	// Read all samples: c1 c2 ... cn c1 c2 ... cn ...
	// Note: A frame is a group c1 c2 ... cn
	vector<short> samples(nChannels * nFrames);
	sfhIn.readf(samples.data(), nFrames);

	size_t nBlocks { static_cast<size_t>(ceil(static_cast<double>(nFrames) / bs)) };

	// Do zero padding, if necessary
	samples.resize(nBlocks * bs * nChannels);

	// Vector for holding all DCT coefficients, channel by channel
	vector<vector<short>> x_dct( vector<short>(nBlocks * bs));

	// Vector for holding DCT computations
	vector<double> x(bs);

      

	// Direct DCT
	fftw_plan plan_d = fftw_plan_r2r_1d(bs, x.data(), x.data(), FFTW_REDFT10, FFTW_ESTIMATE);
	for(size_t n = 0 ; n < nBlocks ; n++)
		for(size_t c = 0 ; c < nChannels ; c++) {
			for(size_t k = 0 ; k < bs ; k++)
				x[k] = samples[(n * bs + k) * nChannels + c];

			fftw_execute(plan_d);
			// Keep only "dctFrac" of the "low frequency" coefficients
			for(size_t k = 0 ; k < bs * dctFrac ; k++)
				x_dct[c][n * bs + k] = x[k] / (bs << 1);

		}

WAVQuant out(16,8); 

    // Quantize DCT coefficients
    vector<short> quant_data;
    for(size_t c = 0 ; c < nChannels ; c++) {
        out.quantization(x_dct[c]);
        quant_data= out.getQuantizedVector();
    }

    // Write quantized DCT coefficients to binary file using bitstream
    ofstream out_file("out2.bin", ios::binary);
    bitstream out_stream("out2.bin","w");
    for(size_t c = 0 ; c < nChannels ; c++) {
        for(size_t k = 0 ; k < quant_data[c].size() ; k++) {
            out_stream.writeBit((quant_data[c][k]>>(7-k)));
        }

    }    
    out_stream.close();

    // Read quantized DCT coefficients from binary file using bitstream
    ifstream in_file("out2.bin", ios::binary);
    bitstream in_stream("out2.bin","r");
    vector<vector<short>> x_dct2(nChannels, vector<double>(nBlocks * bs));
    for(size_t c = 0 ; c < nChannels ; c++) {
        for(size_t k = 0 ; k < x_dct2[c].size() ; k++) {
            x_dct2[c][k] = in_stream.readBit();
        }
    }



	// Inverse DCT
	fftw_plan plan_i = fftw_plan_r2r_1d(bs, x.data(), x.data(), FFTW_REDFT01, FFTW_ESTIMATE);
	for(size_t n = 0 ; n < nBlocks ; n++)
		for(size_t c = 0 ; c < nChannels ; c++) {
			for(size_t k = 0 ; k < bs ; k++)
				x[k] = x_dct[c][n * bs + k];

			fftw_execute(plan_i);
			for(size_t k = 0 ; k < bs ; k++)
				samples[(n * bs + k) * nChannels + c] = static_cast<short>(round(x[k]));

		}

	sfhOut.writef(samples.data(), sfhIn.frames());
    return 0;
}
