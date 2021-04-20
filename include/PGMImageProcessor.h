#ifndef PGMIP_H
#define PGMIP_H
#include <string>

class PGMImageProcessor{

    private:
        int rows, cols;
        unsigned char ** image;
    public: 
        PGMImageProcessor(std::string filename);
        ~PGMImageProcessor();
        PGMImageProcessor(const PGMImageProcessor &p);
        unsigned char** loadImage(std::string filename);
        void writeImage(std::string filename,unsigned char ** image);
    
};

#endif