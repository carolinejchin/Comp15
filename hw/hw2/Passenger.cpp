/*
 * HW2: Metro Simulator 
 * cs15
 * Passenger.cpp
 * Caroline Chin 
 * 10/13/2021
 * Implementation of Passenger class which includes a print function for the 
 * Passenger struct.
 */

#include <iostream>
#include <string>
#include "Passenger.h"
using namespace std;

/*    print 
 *     Purpose: prints a passenger 
 *    Parameters: output file 
 *    Returns: none 
 *    Notes: prints to output file 
 */
void Passenger::print(std::ostream &output)
{
    output << "[" << id << ", " << from << "->" << to << "]" 
           << std::endl;
}
