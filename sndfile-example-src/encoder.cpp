#include <iostream>
#include <fstream>
#include <string>
#include "bitstream.h"

using namespace std;

int main(int argc, char* argv[]){
    string mode = "w";            
    string bin (argv[argc-1]);
    string txt (argv[argc-2]);
    int num = 0;


    bitstream bitstream (bin, mode);   
        ifstream ifs (txt);
        char op;
        printf("Encode all contents of the txt file->A\n");
        printf("Econde N bits of the txt?->N\n");
        cin >> op;
        if (op == 'A'){
            int val;
            while (ifs >> val){
                bitstream.writeBit(val);
                cout << val << endl;
            }
            printf("Finished");
        }
        else if(op == 'N'){
            printf("Number of bits to encode:\n");
            cin >> num;
            int tmp[num];
            for (int i = 0; i < num; i++){
                ifs >> tmp[i];
                // printf("Bit %d:%d ", i, tmp[i]);kvc
            }
            bitstream.writeNBits(tmp,num);
            printf("Finished");
        }
        
    bitstream.close();
    ifs.close();

    return 0; 
}