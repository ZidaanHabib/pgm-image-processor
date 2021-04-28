#include <vector>
#include <string>
#include "ConnectedComponent.h"
#include <utility>
#include <stdio.h>
#define print(x) std::cout << x << std::endl;

int ConnectedComponent::numComponents = 0; // intialise ConnectedComponent counter

ConnectedComponent::ConnectedComponent() : numPixels(0), num_boundary_pixels(0) {
    id = numComponents;
    ++numComponents; // increase count of exisitng connected components
}
ConnectedComponent::ConnectedComponent(int row, int col) : numPixels(1), num_boundary_pixels(0) {
    id = numComponents;
    ++numComponents;
    pixels.push_back(std::make_pair(row, col));
}

ConnectedComponent::~ConnectedComponent(){ // destructor
    
} 

ConnectedComponent::ConnectedComponent(const ConnectedComponent & c) : numPixels(c.numPixels ), num_boundary_pixels(c.num_boundary_pixels) { // copy constructor
    id = numComponents; // can't copy c's id, has to be unique
    ++numComponents;
    if(!c.pixels.empty()){
        std::vector< std::pair<int,int> >::const_iterator it;
        for (it = c.pixels.begin(); it != c.pixels.end(); ++it){
            pixels.push_back(*it);
        }
    }
}

ConnectedComponent& ConnectedComponent::operator=(const ConnectedComponent & rhs)  { // copy assignment operator
    if(this != &rhs){ // ensure not self-assignment
        this-> numPixels = rhs.numPixels;
        this->num_boundary_pixels = rhs.num_boundary_pixels;
        this->id = numComponents;
        ++numComponents;

        if(!rhs.pixels.empty()){
        std::vector< std::pair<int,int> >::const_iterator it;
        for (it = rhs.pixels.begin(); it != rhs.pixels.end(); ++it){
            this->pixels.push_back(*it);
        }
    }
    }
    return *this;
}

ConnectedComponent::ConnectedComponent(ConnectedComponent && c) : numPixels(c.numPixels), id(c.id), num_boundary_pixels(c.num_boundary_pixels){ // move constructor
    if(!c.pixels.empty()){
        std::vector< std::pair<int,int> >::iterator it;
        for (it = c.pixels.begin(); it != c.pixels.end(); ++it){
            this->pixels.push_back(*it);
        }
    }
}

ConnectedComponent& ConnectedComponent::operator=(ConnectedComponent && rhs){ // move assignment operator
    if(this != &rhs){ //ensure not self-assignment
        this-> numPixels = rhs.numPixels;
        this->id = rhs.id;
        this->num_boundary_pixels = rhs.num_boundary_pixels;
        if(!rhs.pixels.empty()){
            std::vector< std::pair<int,int> >::iterator it;
            for (it = rhs.pixels.begin(); it != rhs.pixels.end(); ++it){
                this->pixels.push_back(*it);
            }
        }
    }
    return *this;
}

void ConnectedComponent::addPixel(int row, int col){
    pixels.push_back(std::make_pair(row, col));
    ++numPixels;
}

void ConnectedComponent::addBoundaryPixel(int row, int col){
    boundary_pixels.push_back(std::make_pair(row, col));
    ++num_boundary_pixels;
}

void ConnectedComponent::printData(void){
    printf("Connected Component %d:\n", id);
    printf("    Number of pixels: %d\n", numPixels);
    printf("    Number of component boundary pixels: %d\n", numPixels);
}