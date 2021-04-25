#include <string>
#include <iostream>
#include <fstream>
#include "PGMImageProcessor.h"

#define print(x) std::cout << x << std::endl;
#define OUTPUTDIR "output/"

int main(int argc, char* argv[]){
    int i = 1;
    int min = 3; //default min size
    int max ;
    unsigned char threshold = 128;
    bool print = false;
    std::string input_filename,output_filename;
    while(i < argc-1){
        std::string arg = argv[i];
        if(arg == "-s"){
            min = std::stoi(argv[i+1]);
            max = std::stoi(argv[i+2]);
        }
        else if (arg == "-t"){
            threshold = std::stoi(argv[i+1]);
            
        } 
        else if (arg == "-p"){
            print = true;
        }
        else if (arg == "-w"){

            output_filename = OUTPUTDIR;
            output_filename += argv[i+1]; 
        }
        ++i;
    }
    input_filename = input_filename+  argv[argc-1];

    PGMImageProcessor img_processor(input_filename); // create PGMImageProcessor object
    
    int num = img_processor.extractComponents(threshold);
    return 0;
}