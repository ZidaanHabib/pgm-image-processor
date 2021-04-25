#include <string>
#include <iostream>
#include <fstream>
#include "PGMImageProcessor.h"

#define print(x) std::cout << x << std::endl;
#define OUTPUTDIR "output/"

/* Used for testing: 
void writeImage(std::string filename,  unsigned char ** img, int rows, int cols){
    std::ofstream ofs(filename, std::ios::binary | std::ios::out);
    ofs << "P5"<< "\n";
    ofs << cols << " " << rows <<"\n";
    ofs << 255 <<"\n";
    //ofs.write(reinterpret_cast<char*>(*(img)) , cols*rows);
    for(int i = 0; i< rows; ++i){
        ofs.write(reinterpret_cast<const char*>((img[i])) , cols);
    }
    ofs.close();
} */


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
    /*
    unsigned char ** img = new unsigned char*[252]; // allocate mem for outer array
    for (int i = 0; i < 252; ++i){ //intialise image of black pixels
        img[i] = new unsigned char[609];
        for(int j = 0; j< 609; ++j){
            img[i][j] = 0;
        }
    }
    for (int i = 0; i < 252; ++i){ //intialise image of black pixels
        for(int j = 0; j< 609; ++j){
            if(img[i][j] != 0) print("wtf");
        }
    }
    writeImage("test.pgm", img, 252,609); */

    PGMImageProcessor img_processor(input_filename); // create PGMImageProcessor object
    
    int num = img_processor.extractComponents(threshold);
    bool success = img_processor.writeComponents(output_filename);
    

    return 0;
}