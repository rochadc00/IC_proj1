#include <iostream>
#include <sndfile.hh>
#include <vector>
#include <string.h>

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

short echo = NULL;

void singleEcho(vector<short> &samples, vector<short> &res, int sampleRate);

int main(int argc, char *argv[]) {


	if(argc < 4) {
		cerr << "Usage: " << argv[0] << " <input file> <output_file> <effect>\n";
		return 1;
	}

	SndfileHandle sndFileIn { argv[argc-3] };
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

    SndfileHandle sndFileOut { argv[argc-2], SFM_WRITE, sndFileIn.format(),
    sndFileIn.channels(), sndFileIn.samplerate() };
	if(sndFileOut.error()) {
		cerr << "Error: invalid output file\n";
		return 1;
    }

    size_t nFrames;
    vector<short> samples(FRAMES_BUFFER_SIZE * sndFileIn.channels());
    vector<short> res(FRAMES_BUFFER_SIZE * sndFileIn.channels());

    // for(int i = 0; i < argc; i++) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }

    if(strcmp(argv[argc-1], "single-echo") == 0) {
        while(nFrames = sndFileIn.readf(samples.data(), FRAMES_BUFFER_SIZE)) {
            samples.resize(nFrames * sndFileIn.channels());
            singleEcho(samples, res, sndFileIn.samplerate());
            sndFileOut.writef(res.data(), nFrames);
        }

    } else {
        cout << "Effect " << argv[argc-1] << " does not exist." << endl;
    }

    return 0;
}

// y(n) = x(n) + ax(n-1)
// y(n) = x(n) + a[0,1] * x(n - delay)
// delay = (variacao do sample rate) / (1+a)
void singleEcho(vector<short> &samples, vector<short> &res, int sampleRate) {
    double a = 0.6;
    size_t delay = sampleRate; // / (1 + a);
    // double delay = 0.6;
    for(size_t i = 0; i < samples.size(); i++) {
        res[i] = (samples[i] + samples[i-delay]) * a;
    }
}
