#ifndef PGMIP_H
#define PGMIP_H
#include <string>

class PGMImageProcessor{

    private:
        int rows, cols;
        unsigned char ** image;
    public: 
        PGMImageProcessor();
        unsigned char** loadImage(std::string filename);
};

#endif