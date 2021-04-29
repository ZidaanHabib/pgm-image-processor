#include <string>
#include <iostream>
#include <fstream>
#include "PGMImageProcessor.h"

#define print(x) std::cout << x << std::endl;
#define OUTPUTDIR "output/"


int main(int argc, char* argv[]){
    int i = 1;
    int min = 3;
    int max;
    unsigned char threshold = 128;
    bool print = false, colour = false, boundary = false, write = false;
    std::string input_filename,output_filename, colour_output_file, boundary_output_file;
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
            write = true;
        }
        else if(arg == "-c"){
            colour_output_file = OUTPUTDIR;
            colour_output_file+= argv[i+1];
            colour = true;
        }
        else if(arg == "-b"){
            boundary_output_file = OUTPUTDIR;
            boundary_output_file+= argv[i+1];
            boundary = true;
        }
        ++i;
    }
    input_filename = input_filename+  argv[argc-1];


    PGMImageProcessor img_processor(input_filename); // create PGMImageProcessor object

    print("Processing...");
    int numConnectedComponents = img_processor.extractComponents(threshold, min);
    img_processor.extractBoundaryPixels();
    print("Connected components extracted.");
   
    if(write){
        bool success = img_processor.writeComponents(output_filename);//write ppm file if user specified it
    }
    if(colour){
        img_processor.writeColouredComponents(colour_output_file);//write ppm file if user specified it
    }
    if(boundary){
        img_processor.writeBoundaryPixels(boundary_output_file);//write ppm file if user specified it
    }
    if(print){
        img_processor.printComponentInfo();
    }

    return 0;
}