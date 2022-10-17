#include <iostream>
#include <sndfile.hh>
#include <vector>

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

	if(argc < 3) {
		cerr << "Usage: " << argv[0] << " <input file> <output_file>\n";
		return 1;
	}

    
	SndfileHandle sndFileIn { argv[argc-2] };
	if(sndFileIn.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

    if((sndFileIn.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) {
		cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if((sndFileIn.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

    SndfileHandle sndFileOut { argv[argc-1], SFM_WRITE, sndFileIn.format(),
    sndFileIn.channels(), sndFileIn.samplerate() };
	if(sndFileOut.error()) {
		cerr << "Error: invalid output file\n";
		return 1;
    }

    size_t nFrames;
    vector<short> samples(FRAMES_BUFFER_SIZE * sndFileIn.channels());
    vector<short> res(FRAMES_BUFFER_SIZE * sndFileIn.channels());
    
    while(nFrames = sndFileIn.readf(samples.data(), FRAMES_BUFFER_SIZE)) {
        samples.resize(nFrames * sndFileIn.channels());
    }

    return 0;
}