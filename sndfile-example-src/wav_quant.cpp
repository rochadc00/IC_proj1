#include <iostream>
#include <sndfile.hh>
#include <vector>
#include "wav_quant.h"
// #include "matplotlibcpp.h"

using namespace std;
// namespace plt = matplotlibcpp;


constexpr size_t FRAMES_BUFFER_SIZE = 65536;

int main(int argc, char *argv[]) {
    
    if(argc < 3) {
		cerr << "Usage: " << argv[0] << " <input_file> <channel> <output_file>\n";
		return 1;
	}

	SndfileHandle sndFile { argv[argc-3] };
	if(sndFile.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

	if((sndFile.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) {
		cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if((sndFile.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

	int channel { stoi(argv[argc-2]) };
	if(channel >= sndFile.channels()) {
		cerr << "Error: invalid channel requested\n";
		return 1;
	}

    SndfileHandle sfhOut { argv[argc-1], SFM_WRITE, sndFile.format(),
    sndFile.channels(), sndFile.samplerate() };
	if(sfhOut.error()) {
		cerr << "Error: invalid output file\n";
		return 1;
    }

    int nBits;
    cout << "How many bits do you want to remove sample?\n";
    cin >> nBits;

    if(nBits < 1 || nBits > 15) {
        cerr << "Error: invalid number of bits\n";
        return 1;
    }

    size_t nFrames;
    vector<short> samples(FRAMES_BUFFER_SIZE * sndFile.channels());
    vector<short> quantized_vector(FRAMES_BUFFER_SIZE * sndFile.channels());

    while((nFrames = sndFile.readf(samples.data(), FRAMES_BUFFER_SIZE))) {
		samples.resize(nFrames * sndFile.channels());
        WAVQuant quant {samples.size(), short(nBits)};
        quant.quantization(samples);
        quantized_vector = quant.getQuantizedVector();
        sfhOut.writef(quant.getQuantizedVector().data(), nFrames);
    }

    return 0;
}
