#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "BitStream.hh"

using namespace std;

int main(int argc, char* argv[]){
    
    BitStream bstream_r("read.txt", "write.txt");
    
    // read.txt contem um '7'
    // deverão ser impressos os primeiros 4 bits
    // da representação ascii de '7' 
    for(char x : bstream_r.readNBits(4)){
        cout << x;
    }
    cout << endl; // funciona

    bstream_r.writeNBits("101"); // write on output file
    bstream_r.close();


    BitStream bstream_w("write.txt", "");
    string written = bstream_w.readNBits(4);   // read the output file

    cout << written << endl; 

    bstream_w.close();

    return 0;
}