/*
 * HW2: Metro Simulator 
 * cs15
 * main.cpp
 * Caroline Chin 
 * 10/13/2021
 * Takes in command line files, creates simulation and runs simulation.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "MetroSim.h"

using namespace std;

/*    main 
 *    Purpose: opens and closes files,
 *             creates instance of metrosim, calls run_command_loop
 *    Parameters: number of elements in command line, elements in command line 
 *    Returns: 0
 */
int main(int argc, char *argv[])
{
    //opens files
    ifstream input;
    input.open(argv[1]);
    
    ofstream output;
    output.open(argv[2]);
    
    ifstream command_file;
    command_file.open(argv[3]);
        
    if (not input.is_open()) {
        cerr << "Error: could not open file " <<  argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    //creates instance of MetroSim/reads in station files 
    MetroSim sim(input);
    //determines if commands are read in through cin or command file 
    if (argc == 3) {
        sim.run_command_loop(cin, output);
    }
    else {
        sim.run_command_loop(command_file, output);
    }
    //close files
    input.close();
    output.close();
    command_file.close();
    return 0;
}


