To build:
	make

To test:
	../sndfile-example-bin/wav_cp sample.wav copy.wav // copies "sample.wav" into "copy.wav"
	../sndfile-example-bin/wav_hist sample.wav 0 // outputs the histogram of channel 0 (left)
	../sndfile-example-bin/wav_dct sample.wav out.wav // generates a DCT "compressed" version
	../sndfile-example-bin/wav_quant sample.wav 0 output.wav	// quantizes the sample.wav and writes it into output.wav
