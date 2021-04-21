#ifndef PGMIP_H
#define PGMIP_H
#include <string>

class PGMImageProcessor{

    private:
        int rows, cols;
        unsigned char ** image;
    public: 
        PGMImageProcessor(std::string filename); //Custom constructor
        ~PGMImageProcessor(); // destructor
        PGMImageProcessor(const PGMImageProcessor &p); // copy constructor
        PGMImageProcessor& operator=(const PGMImageProcessor & rhs); // copy assignment constructor
        PGMImageProcessor(PGMImageProcessor && p); // move constructor
        PGMImageProcessor& operator=(PGMImageProcessor && rhs); //move assignment operator
        unsigned char** loadImage(std::string filename);
        void writeImage(std::string filename,unsigned char ** image);
    
};

#endif