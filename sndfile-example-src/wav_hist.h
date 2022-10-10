#ifndef WAVHIST_H
#define WAVHIST_H

#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>
#include <cmath>
#include <fstream>

class WAVHist {
  private:
	std::vector<std::map<short, size_t>> counts;
	std::map<short, size_t> mid;
	std::map<short, size_t> side;
	std::map<short, size_t> quantized;
	std::map<short, size_t> MID_channel;

  public:
	WAVHist(const SndfileHandle& sfh) {
		counts.resize(sfh.channels());
	}

	void update(const std::vector<short>& samples) {
		size_t n { };
		for(auto s : samples)
			counts[n++ % counts.size()][s]++;
	}

	void dump(const size_t channel) const {
		for(auto [value, counter] : counts[channel])
			std::cout << value << '\t' << counter << '\n';
	}

	void mid_channel(const std::vector<short>& samples) {
		for(size_t i = 1; i <= samples.size(); i += 2) {
			int mid_value = (samples[i-1] + samples[i]) / 2;
			mid[mid_value]++;
		}
		for(const auto& elem : mid)
			std::cout << elem.first << '\t' << elem.second << '\n';
	}

	void side_channel(const std::vector<short>& samples) {
		for(size_t i = 1; i <= samples.size(); i += 2) {
			int side_value = (samples[i-1] - samples[i]) / 2;
			side[side_value]++;
		}

		for(const auto& elem : side)
			std::cout << elem.first << '\t' << elem.second << '\n';
	}
};

#endif

