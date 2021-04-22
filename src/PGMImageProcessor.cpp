#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include "PGMImageProcessor.h"
#include "ConnectedComponent.h"




/**
 * Custom constructor
 * @param filename : name of image file to load
 */
PGMImageProcessor::PGMImageProcessor(std::string filename){
    image = loadImage(filename);
}

/**
 * Destructor
 */
PGMImageProcessor::~PGMImageProcessor(){
    for (int i=0; i< rows;++i){
        delete image[i];
    }
    delete image;
}

/**
 * Copy constructor
 * @param p : Reference to PGMImageProcessor object to copy
 */
PGMImageProcessor::PGMImageProcessor(const PGMImageProcessor &p) : rows(p.rows), cols(p.cols), image(nullptr) {
    if(p.image != nullptr){
        //image = new unsigned char*[p.rows]; iamge already exists and != nullptr so dont think we have to create it again
        for (int i=0;i<p.rows; ++i){
            for (int j = 0; j<p.cols; ++j){
                image[i][j] = p.image[i][j];
            }
        }
    }
}

/**
 * Copy assignment operator
 * @param rhs : Reference to PGMImageProcessor object to copy
 */
PGMImageProcessor& PGMImageProcessor::operator=(const PGMImageProcessor & rhs){
    if(this != &rhs){ // make sure not self-assignment
        this-> rows = rhs.rows;
        this-> cols = rhs.cols;

        if(this->image != nullptr){ // check if object we are assigning already has an image variable pointing to a memory location
            for (int i = 0; i< this->rows; ++i){
                delete [] this->image[i];
            }
            delete [] this->image;
        }
        if(rhs.image != nullptr){
            this->image = new unsigned char*[rhs.rows];
            for (int i=0;i<rhs.rows; ++i){
                for (int j = 0; j<rhs.cols; ++j){
                    this->image[i][j] = rhs.image[i][j];
                }   
            }
        }

    }
    return *this;

}
/**
 * Move constructor
 * @param p :  PGMImageProcessor object to copy
 */
PGMImageProcessor::PGMImageProcessor(PGMImageProcessor && p) : rows(p.rows), cols(p.cols), image(p.image) { //Does ownership of inner arrays need to be transferred explicitly?
    p.image = nullptr;
}

/**
 * Move assignment operator
 * @param rhs :  PGMImageProcessor object whose ownership to transfer
 */
PGMImageProcessor& PGMImageProcessor::operator=(PGMImageProcessor && rhs)  {
    if(this != &rhs){ // ensure not self-assignment
        this->rows = rhs.rows;
        this-> cols = rhs.cols;

        if (this->image != nullptr){
            for(int i = 0 ; i < this->rows; ++i){
                delete [] this-> image[i]; //delete current image inner arrays because it is being replaced
            }
            delete [] this-> image; //delete current image outer array
            this-> image = nullptr;
        }

        if(rhs.image != nullptr){
            this->image = rhs.image; //transfer ownership of rhs's image to this
            rhs.image = nullptr; 
        }
    }

    return *this;
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

int PGMImageProcessor::extractComponents(unsigned char threshold){
    std::queue<std::pair<int, int > > q; // queue to hold untested neighbours
    for (int i = 0; i < rows;++i){
        for(int j = 0 ; j < cols; ++j){
            if(image[i][j] >= threshold){
                std::unique_ptr<ConnectedComponent> ptr(new ConnectedComponent(i, j)); // create pointer to new connecetd component
                image[i][j] = 0; // set current pixel to 0 so not revisited
                if(j < cols -1){// check that we are not on boundary of image
                    if(image[i][j+1] >= threshold){ //  check right neighbour
                        ptr->addPixel(i, j+1);
                        image[i][j+1] = 0; //make sure not revisited
                        addNeighboursToQueue(q,i, j+1);
                    }
                } 
                if(i < rows -1){// check that we are not on boundary of image
                    if(image[i+1][j] >= threshold){ //  check bottom neighbour
                        ptr->addPixel(i+1, j);
                        image[i+1][j] = 0; //make sure not revisited
                        addNeighboursToQueue(q,i+1, j);
                    }
                }
                //TODO: while loop to handle queue
                while(!q.empty()){
                    std::pair<int, int> coords  = q.front();
                    q.pop();
                    int x = coords.first;
                    int y = coords.second;
                    if(image[y][x] >= threshold){
                     ptr->addPixel(y,x); // add pixel to connected component
                     image[y][x] = 0; // make sure it won't be revisited
                     addNeighboursToQueue(q,y,x); // add neighbors to q
                    }
                }   
            }
            
        }
    }
}

/**
 * Auxillary method for extractComponent() to add left, right, and bottom neighbour to queue
 * @param neighbours : queue of neighbour coordinates
 * @param row : row number of current pixel
 * @param col : col number of current pixel
 */
void PGMImageProcessor::addNeighboursToQueue(std::queue<std::pair<int, int> > &neighbours, int row, int col){
    if (col != cols-1){ // check we're not at right side boundary
        neighbours.push(std::make_pair(row,col+1)); //right neighbour
    }
    if (col != cols > 0){ // check we're not at left side boundary
        neighbours.push(std::make_pair(row,col-1)); //left neighbour
    }
    if (row != rows-1 > 0){ // check we're not at bottom boundary
        neighbours.push(std::make_pair(row+1,col)); //bottom neighbour
    }
}

