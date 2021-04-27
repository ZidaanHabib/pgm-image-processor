#ifndef PGMIP_H
#define PGMIP_H
#include <string>
#include <memory>
#include <list>
#include <queue>
#include <utility>
#include "ConnectedComponent.h"
#include <array>
#include <tuple>

class PGMImageProcessor{

    private:
        int rows, cols,
            min = 3, max = rows*cols;
        unsigned char ** image;
        std::list<std::unique_ptr<ConnectedComponent> > components;
        static unsigned char colours[5][3] ;

    public: 
        PGMImageProcessor(std::string filename); //Custom constructor
        ~PGMImageProcessor(); // destructor
        PGMImageProcessor(const PGMImageProcessor &p); // copy constructor
        PGMImageProcessor& operator=(const PGMImageProcessor & rhs); // copy assignment constructor
        PGMImageProcessor(PGMImageProcessor && p); // move constructor
        PGMImageProcessor& operator=(PGMImageProcessor && rhs); //move assignment operator
        void loadImage(std::string filename); 
        void writeImage(std::string filename, unsigned char ** img);
        bool writeComponents(const std::string &filename );
        int extractComponents(unsigned char threshold, int minValidSize);
        void addNeighboursToQueue(std::queue<std::pair<int, int> > &neighbours, int row, int col);
        unsigned char ** getImage(void);
        int filterComponentsBySize(int minSize, int maxSize);
        void writeColouredComponents(const std::string &filename);
    
};

#endif  