#include <iostream>
#include <sndfile.hh>
#include <vector>
#include <math.h>

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536;

int main(int argc, char *argv[]) {

    if(argc < 3) {
		cerr << "Usage: " << argv[0] << " <original_file> <compressed_file>\n";
		return 1;
	}

    SndfileHandle originalFile { argv[1] };
    SndfileHandle compressedFile { argv[2] };
    if(originalFile.error() || compressedFile.error()) {
        cerr << "Error: invalid input file\n";
        return 1;
    }

    if(((originalFile.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) || ((compressedFile.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV)) {
		cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if(((originalFile.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) || (compressedFile.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

    if(originalFile.channels() * originalFile.samplerate() != compressedFile.channels() * compressedFile.samplerate()) {
        cerr << "Error: Both files should have the same number of samples" << endl;
        return 1;
    }

    double Ex = 0;
    double Er = 0;
    double SNR = 0;
    double nSamples = originalFile.channels() * originalFile.frames();

    size_t nFramesOriginal;
    size_t nFramesCompress;
    vector<short> originalSamples(FRAMES_BUFFER_SIZE * originalFile.channels());
    vector<short> compressedSamples(FRAMES_BUFFER_SIZE * compressedFile.channels());
    double maxAbsError = 0;
    while((nFramesOriginal = originalFile.readf(originalSamples.data(), FRAMES_BUFFER_SIZE)), (nFramesCompress = compressedFile.readf(compressedSamples.data(), FRAMES_BUFFER_SIZE))) {
        originalSamples.resize(nFramesOriginal * originalFile.channels());
        compressedSamples.resize(nFramesCompress * compressedFile.channels());
        for(size_t i = 0; i < originalSamples.size(); ++i) {
            Er = Er + pow(originalSamples[i] - compressedSamples[i], 2);
            Ex = Ex + pow(originalSamples[i], 2);
            if(maxAbsError < abs(originalSamples[i] - compressedSamples[i])) {
                maxAbsError = abs(originalSamples[i] - compressedSamples[i]);
            }
        }
    }

    // lim(1/(2n+1)) = 1/n
    Ex = (1/nSamples) * Ex;
    Er = (1/nSamples) * Er;

    SNR = 10*log10(Ex/Er);
    cout << "SNR: " << SNR << endl;
    cout << "Max Absolute Error: " << maxAbsError << endl;

    return 0;
}