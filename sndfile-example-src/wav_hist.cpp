#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "wav_hist.h"
#include <string.h>

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

	if(argc < 3) {
		cerr << "Usage: " << argv[0] << " <input file> <channel> <mode>\n mode: \n\t-mid\n\t-side ";
		return 1;
	}

	SndfileHandle sndFile { argv[1] };
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

	int channel { stoi(argv[2]) };
	if(channel >= sndFile.channels()) {
		cerr << "Error: invalid channel requested\n";
		return 1;
	}

	size_t nFrames;
	vector<short> samples(FRAMES_BUFFER_SIZE * sndFile.channels());
	WAVHist hist { sndFile };

	if(argc == 3) {
		while((nFrames = sndFile.readf(samples.data(), FRAMES_BUFFER_SIZE))) {
			samples.resize(nFrames * sndFile.channels());
			hist.update(samples);
		}
		hist.dump(channel);
	} else {
		if(strcmp(argv[3], "-side")) {
			while((nFrames = sndFile.readf(samples.data(), FRAMES_BUFFER_SIZE))) {
				samples.resize(nFrames * sndFile.channels());
				hist.mid_channel(samples);
			}
		} else if(strcmp(argv[3], "-mid")) {
			while((nFrames = sndFile.readf(samples.data(), FRAMES_BUFFER_SIZE))) {
				samples.resize(nFrames * sndFile.channels());
				hist.side_channel(samples);
			}
		}
	}

	return 0;
}

