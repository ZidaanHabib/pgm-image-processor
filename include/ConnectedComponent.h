#ifndef CC_H
#define CC_H 
#include <vector>
#include <utility>

class ConnectedComponent {
    private: 
        friend class PGMImageProcessor;
        int numPixels;
        int id;
        std::vector<std::pair<int, int> > pixels;
        static int numComponents;
        int num_boundary_pixels;
        std::vector<std::pair<int, int> > boundary_pixels;

        //Methods:
        ConnectedComponent(); // default constructor    
        ConnectedComponent(int row, int col);
        ConnectedComponent(const ConnectedComponent & c); // copy constructor
        ConnectedComponent& operator=(const ConnectedComponent & rhs); // copy assignment operator
        ConnectedComponent(ConnectedComponent && c); // move constructor
        ConnectedComponent& operator=(ConnectedComponent && rhs); // move assignment operator
        void addPixel(int x, int y);
        void addBoundaryPixel(int x, int y);
    public:
        ~ConnectedComponent(); // destructor
        
};




#endif