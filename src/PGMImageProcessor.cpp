#include <string>
#include <iostream>
#include <fstream>
#include "PGMImageProcessor.h"

unsigned char**  PGMImageProcessor::loadImage(std::string filename){
    std::ifstream ifs(filename, std::ios::binary);

    while (ifs){ //while loop to get or discard header info
        std::string line;
        ifs >> std::ws; //consume white space
        std::getline(ifs, line);
        if (line.substr(0,1) == "#" || line.substr(0,1) == "P"){
            //std::cout << line << std::endl;
            continue;
        }
        //now nrows and ncols are on this line
        cols = std::stoi(line);
        line.erase(0,line.find(" "));
        rows = std::stoi(line);
        std::cout << "Loaded image of dimensions " << cols << " x "<< rows << std::endl;
        ifs >> std::ws; //consume whitespace
        std::getline(ifs, line); // 255 line
        break;
    }

    image = new unsigned char * [rows]; //allocate memory for outer array
    for(int i=0; i<rows; i++){
        image[i] = new  unsigned char[cols]; //allocate memory for inner array
    }
    ifs.read(reinterpret_cast<char*>(*(image)),cols*rows) >> std::ws;  
    ifs.close(); 
    
}  