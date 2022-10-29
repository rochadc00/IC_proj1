#include <iostream>
#include <fstream>
#include <string>
#include "bitstream.h"

using namespace std;

int main(int argc, char* argv[]){
    string mode = "r";
    string bin (argv[argc-1]);
    string txt (argv[argc-2]);
    int num = 0;


    bitstream bitstream (bin, mode);   
        ofstream ofs (txt);
        char op;
        printf("Decode all contents of the txt file->A\n");
        printf("Decode N bits of the txt?->N\n");
        cin >> op;
        if (op == 'A'){
            int bit;
            while ((bit = bitstream.readBit()) != EOF){
                ofs << bit << endl;
                cout << bit << endl;
            }
            printf("Finished");
        }
        else if(op == 'N'){
            printf("Number of bits to encode:\n");            
            cin >> num;
            int tmp[num];
            bitstream.readNBits(num,tmp);    // preenche o array
            for (int i = 0; i < num; i++){  // escreve no txt
                ofs << tmp[i] << endl;
            }
            printf("Finished");
        }
    bitstream.close();

    return 0; 
}