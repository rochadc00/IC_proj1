#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class BitStream{
    public:
        BitStream(string input_File, string output_File);
        int readBit(void);
        string readNBits(int nBits);
        void writeBit(char bit);
        void writeNBits(string nBits);
        vector<int>getBuffer();
        void close();
    private:
        vector<int> buffer;
        int index=0;
        fstream input_File;
        fstream output_File;

        int bitcount = 0;
        char currentByte = 0;

};

BitStream::BitStream(string inF, string outF){
    if(not inF.empty()) {
        input_File.open(inF);
        char c;
        while (input_File.get(c)) {
            for (int i = 0; i < inF.length(); i++) 
                buffer.push_back(((c >> i) & 1));
        }
    }else{
        cout << "No In File to open" << endl;
    }

    if(not outF.empty()){
        output_File.open(outF, fstream::out | fstream::app);
    }else{
        cout << "No Out File to open" << endl;
    }
    
}

int BitStream::readBit(){
    if(input_File.is_open()){
        return buffer.at(index++);
    }else{
        cout << "File not Open!!" << endl;
        return 1;
    }
}

string BitStream::readNBits(int nBits){
    if(input_File.is_open()){
        string nbits_string="";
        int stopCond=index+nBits;
        for( ; index<stopCond ; index++)
            nbits_string += to_string(buffer[index]);
            
        return nbits_string;

    }else{
        cout << "File not Open!!" << endl;
        return "";
    }
}

// doesnt work
void BitStream::writeBit(char bit){
    if(output_File.is_open()){
        currentByte = currentByte <<= 1;
        currentByte |= (0x01 & bit);
        output_File.write(reinterpret_cast<char*>(&buffer), 1);
        bitcount++;
        
    }else{
        cout << "File not Open!!" << endl;
    }

}

void BitStream::writeNBits(string nBits){
    if(output_File.is_open()){
        for(int i=0 ; i<(int)nBits.length() ; i++){
            writeBit(nBits[i]);
        }
    }
}

void BitStream::close(void){
    //BitStream close method
    if(input_File.is_open()){
        input_File.close();
    }
    if(output_File.is_open()){
        output_File.close();
    }
}

vector<int> BitStream::getBuffer(){
    return buffer;
}
