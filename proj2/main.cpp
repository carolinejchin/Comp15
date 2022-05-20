/*
 * main.cpp
 *
 * COMP 15 Project 2: Six Degrees of Collaboration
 * 
 * Takes in command line files, opens files, creates simulation, 
 *  runs simulation and closes files.
 * 
 * by Caroline Chin, 12/7
 */

using namespace std;
#include <iostream>
#include <fstream>
#include "SixDegrees.h"

/*    main
 *    Purpose: creates instance of SixDegrees, calls 
 *      command loop function and opens and closes files
 *    Parameters: # of elements in run line and arguments in 
 *      run line
 *    Returns: 0
 */
int main(int argc, char *argv[])
{
    ifstream artists;
    if (argc == 2 or argc == 3 or argc == 4) {
        artists.open(argv[1]);
        
        if (not artists.is_open()) {
            cerr << argv[1] <<  " cannot be opened." << endl;
            exit(EXIT_FAILURE);
        }
        SixDegrees sim(artists);

        if (argc == 2) {
            sim.run_command_loop(cin, cout);
        }
        else if (argc == 3) {
            ifstream command_file;
            command_file.open(argv[2]);
            sim.run_command_loop(command_file, cout);
            command_file.close();
        }
        else if (argc == 4) {
            ofstream output;
            output.open(argv[3]);
            ifstream command_file;
            command_file.open(argv[2]);
            sim.run_command_loop(command_file, output);
            command_file.close();
            output.close();
        }
        artists.close();
    }
    else {
        cerr << "Usage: SixDegrees dataFile [commandFile] [outputFile]" << endl;
    }
    return 0;
}
