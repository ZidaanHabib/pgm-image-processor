#ifndef PGMIP_H
#define PGMIP_H
#include <string>
#include <memory>
#include <list>
#include "ConnectedComponent.h"

class PGMImageProcessor{

    private:
        int rows, cols;
        unsigned char ** image;
        std::list<std::unique_ptr<ConnectedComponent> > components;

    public: 
        PGMImageProcessor(std::string filename); //Custom constructor
        ~PGMImageProcessor(); // destructor
        PGMImageProcessor(const PGMImageProcessor &p); // copy constructor
        PGMImageProcessor& operator=(const PGMImageProcessor & rhs); // copy assignment constructor
        PGMImageProcessor(PGMImageProcessor && p); // move constructor
        PGMImageProcessor& operator=(PGMImageProcessor && rhs); //move assignment operator
        unsigned char** loadImage(std::string filename); 
        void writeImage(std::string filename,unsigned char ** image);
        int extractComponents(unsigned char threshold);
    
};

#endif  