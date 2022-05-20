/*
 * HW2: Metro Simulator 
 * cs15
 * PassengerQueue.cpp
 * Caroline Chin 
 * 10/13/2021
 * Implementation of PassengerQueue class which includes a print function for  
 * the PassengerQueue vector. Also allows manipulation of PassengerQueue vector.
 */

#include <iostream>
#include <string>
#include "PassengerQueue.h"
#include "Passenger.h"
#include <vector>

/*    front 
 *    Purpose: accesses first passenger within a PassengerQueue
 *    Parameters: none 
 *     Returns: first passenger of PassengerQueue
 */
Passenger PassengerQueue::front() {
    return queue.front();
}

/*    dequeue 
 *    Purpose: removes first passenger of PassengerQueue
 *    Parameters: none 
 *    Returns: none
 */
void PassengerQueue::dequeue() {
    queue.erase(queue.begin());
}

/*    enqueue 
 *    Purpose: adds passenger to front of PassengerQueue
 *    Parameters: passenger being added
 *    Returns: none
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    queue.push_back(passenger);
}

/*    size 
 *    Purpose: returns size of PassengerQueue
 *    Parameters: none 
 *    Returns: int size 
 */
int PassengerQueue::size() {
    return queue.size();
}

/*    at
 *    Purpose: accesses passenger at specific index 
 *    Parameters: index  
 *    Returns: passenger at index 
 */
Passenger PassengerQueue::at(int i) {
    return queue.at(i);
}

/*    print 
 *    Purpose: prints all passengers in PassengerQueue
 *    Parameters: output file
 *    Returns: none
 */
void PassengerQueue::print(ostream &output) {
    for (int i = 0; i < size(); i++) {
        output << "[" << queue.at(i).id << ", " << queue.at(i).from << "->" 
               << queue.at(i).to << "]";
    }
}