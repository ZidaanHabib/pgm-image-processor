# PGM Image Processor
---

Author: Zidaan Habib 


## Instructions for running program:
1. Make sure you are in the project root 
2. type 'make clean' in terminal  to remove any potential object files/ binaries / output images
3. type 'make' to compile program
4. run the program using bin/driver <args> while in the project root. 

## Instructions for running unit tests:
Note that the unit tests are found in the tests/ directory. This directory has its own Makefile.
1. Change to the tests/ directory.
2. run 'make clean' if there is a .o file here
3. run 'make' to compile the unit test executable 
4. run 'make run'

## Note
After a 'make' command, object files are located in the obj/ dir and the executable is in the bin/ directory.The 'make clean' command will clean these folders. 
When images are generated, they are found in the /output directory. They are cleaned with 'make clean'. Only enter the output filenames (not file path)  when entering command line parameters as the program is designed to write images to the output/ directory. For example, bin/driver [some options] -w test.pgm. This will write the test.pgm file to the output. directory.

## Mastery Work
It should also be noted that the Colour Coded Components as well as Boundary Pixel functionality was added. The user can enter -b [output file name] as a command line parameter to extract and output the boundary pixels of components. The user can use -c [output filename ] to write the components to a file using colours. 

## Files:
driver.cpp:
    This is the driver program. It defines the command line parameters that the user can enter. This file creates a PGMImageProcessor instance and calls the appropriate methods depending on what the user enters as command line parameters.

ConnectedComponent.cpp:
This is the file that implements the ConnectedComponent class methods. Such methods include the different constructors as well as methods for adding pixel coordinates to a connected component as well as boundary coordinates as per the mastery work section.

PGMImageProcessor.cpp:
This is the brain of the program. The logic is implemented here. This defines all the image processing methods as well as auxiliary methods for extracting and processing connected components in an image.

ConnectedComponent.h:
Header file to ConnectedComponent.cpp which contains all declarations;

PGMImageProcessor.h:
Header file to PGMImageProcessor.cpp which contains all declarations;

