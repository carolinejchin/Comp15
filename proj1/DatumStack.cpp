/*
 * Proj1 CalcYouLater
 * cs15
 * DatumStack.cpp
 * Caroline Chin 
 * 10/21/2021
 * Implementation of DatumStack class allows manipulation of 
 * DatumStack vector.
 */


#include "Datum.h"
#include "DatumStack.h"
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

/*    Default Constructor 
 *    Purpose: creates an empty DatumStack
 *    Parameters: none 
 */
DatumStack::DatumStack() {
    vector <Datum> empty;
    stack = empty;
}

/*    Constructor 
 *    Purpose: creates a DatumStack with given array and size
 *    Parameters: an array of Datums and its size
 */
DatumStack::DatumStack(Datum arr[], int size) {
    for(int i = 0; i < size; i++) {
        Datum temp = arr[i];
        stack.insert(stack.begin(), temp);
    }    
}

/*    isEmpty
 *    Purpose: checks if a DatumStack is empty
 *    Parameters: none 
 *    Returns: true or false 
 */
bool DatumStack::isEmpty() {
    return stack.empty();
}

/*    clear
 *    Purpose: clears a DatumStack's elements
 *    Parameters: none 
 *    Returns: none
 */
void DatumStack::clear() {
    stack.clear();
}

/*    size
 *    Purpose: returns the size of a DatumStack
 *    Parameters: none 
 *    Returns: a size of type int
 */
int DatumStack::size() {
    return stack.size();
}

/*    top
 *    Purpose: returns the top Datum of a DatumStack
 *    Parameters: none 
 *    Returns: top Datum of DatumStack
 */
Datum DatumStack::top() {
    if(stack.empty()) {
        throw runtime_error("empty_stack");
    }
    return stack.at(0);
}

/*    pop
 *    Purpose: removes top element of DatumStack
 *    Parameters: none 
 *    Returns: none
 */
void DatumStack::pop() {
    if(stack.empty()) {
        throw runtime_error("empty_stack");
    }
    stack.erase(stack.begin());
}

/*    push 
 *    Purpose: adds a Datum to the top of the DatumStack
 *    Parameters: A Datum
 *    Returns: none
 */
void DatumStack::push(Datum d) {
    stack.insert(stack.begin(), d);
}