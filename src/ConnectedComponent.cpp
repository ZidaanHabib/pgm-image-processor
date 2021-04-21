#include <vector>
#include <string>
#include "ConnectedComponent.h"
#include <utility>

int ConnectedComponent::numComponents = 0; // intialise ConnectedComponent counter

ConnectedComponent::ConnectedComponent() : numPixels(0) {
    id = numComponents;
    ++numComponents; // increase count of exisitng connected components
    

}

ConnectedComponent::~ConnectedComponent(){ // destructor
    
} 

ConnectedComponent::ConnectedComponent(const ConnectedComponent & c) : numPixels(c.numPixels ) { // copy constructor
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

ConnectedComponent::ConnectedComponent(ConnectedComponent && c) : numPixels(c.numPixels), id(c.id){ // move constructor
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
        if(!rhs.pixels.empty()){
            std::vector< std::pair<int,int> >::iterator it;
            for (it = rhs.pixels.begin(); it != rhs.pixels.end(); ++it){
                this->pixels.push_back(*it);
            }
        }
    }
    return *this;
}