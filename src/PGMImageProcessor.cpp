#include <string>
#include <iostream>
#include <fstream>
#include "PGMImageProcessor.h"



PGMImageProcessor::PGMImageProcessor(std::string filename){
    image = loadImage(filename);
}
/**
 * Loads input image
 * @param filename : path of input file
 */
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

    unsigned char ** img = new unsigned char * [rows]; //allocate memory for outer array
    for(int i=0; i<rows; i++){
        img[i] = new  unsigned char[cols]; //allocate memory for inner array
    }
    ifs.read(reinterpret_cast<char*>(*(img)),cols*rows) >> std::ws;  
    ifs.close(); 
    return img;
}  

/**
 * Writes image to PGM file
 * @param filename : name of output file
 */
void PGMImageProcessor::writeImage(std::string filename, unsigned char ** image){
    std::ofstream ofs(filename, std::ios::binary | std::ios::out);
    ofs << "P5"<< std::endl;
    ofs << cols << " " << rows <<std::endl;
    ofs << 255 <<std::endl;
    ofs.write(reinterpret_cast<char*>(*(image)) , cols*rows);

    ofs.close();

}