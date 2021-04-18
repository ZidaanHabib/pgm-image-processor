#include <string>
#include <iostream>
#include <fstream>
#include 

#define print(x) std::cout << x << std::endl;

int main(int argc, char* argv[]){
    int i = 0;
    int min, max, threshold;
    std::string input_filename,output_filename;
    while(i < argc-1){
        std::string arg = argv[i];
        if(arg == "-s"){
            min = std::stoi(argv[i+1]);
            max = std::stoi(argv[i+2]);
        }
        else if (argv[i] == "-t"){
            threshold = std::stoi(argv[i+1]);
        } 
        else if (argv[i] == "-p"){
            print("Print");
        }
        else if (argv[i] == "-w"){
            output_filename = argv[i+1];
        }
    }

    input_filename = argv[argc-1];
}