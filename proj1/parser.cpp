/*
 * Proj1 CalcYouLater
 * cs15
 * parser.cpp
 * Caroline Chin 
 * 10/21/2021
 * Reads in files and returns an rstring 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*    parseRString
 *    Purpose: takes in an input and converts it
 *              into a string and makes sure it is
 *              a valid rString
 *    Parameters: istream input, any istream
 *    Returns: a string/rstring converted from given input
 */
string parseRString (istream & input) {
    string fullPstring;
    string curr;
    //keeps track of number of open and close braces
    int open_brace = 1;
    int close_brace = 0;

    fullPstring = "{";
    //iterates through each individual element
    while(open_brace != close_brace && input >> curr) {
        //adjusts numbers for braces
        if(curr == "{") {
            open_brace++;
        }

        else if(curr == "}") {
            close_brace++;
        }
        fullPstring = fullPstring + " " + curr;
    }
    return fullPstring;
}
/*    main 
 *    Purpose: used as temporary testing for parseRString
 *    Parameters: none 
 *    Returns: 0
 *    Prints: result from parseRString
 *    Notes: must be commented out for unit_test to work
 */
// int main() {
//     ifstream input;
//     input.open("parser.cyl");
//     string result = parseRString(input);
//     input.close();

//     cout << "Result: " << result << endl;

//     return 0;
// }
