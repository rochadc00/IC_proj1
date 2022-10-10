#ifndef WAVQUANT_H
#define WAVQUANT_H

#include <iostream>
#include <vector>
#include <math.h>

class WAVQuant {
    private:
        size_t initialBits;
        short removedBits;
        std::vector<short> quantized_data;
    
    public:
        // finalBits == number of quantization levels
        // removedBits == number of bits removed by quantization
        WAVQuant(size_t initialBits, short removedBits) {
            this->initialBits = initialBits;
            this->removedBits = removedBits;
            this->quantized_data.resize(initialBits);
        }

        // retirar os bits mais significativos
        void quantization(const std::vector<short>& samples) {
            size_t i = 0;
            for(auto& s : samples)
                quantized_data[i++] = s >> this->removedBits;
        }

        std::vector<short> getQuantizedVector() {
            std::vector<short> res; 
            res.resize(this->initialBits);
            size_t i = 0;
            for(auto& s : this->quantized_data)
                res[i++] = s << this->removedBits;
            return res;
        }

};

#endif

/*
bitstream

1) abre stream para leitura(cria objeto tipo bitstream)

2) pede 1 bit("get_bit()")

se tiver um bit disponível no buffer, devolve bit, caso contrário, lê novo byte e devolve bit
*/