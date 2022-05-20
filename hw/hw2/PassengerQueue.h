/*
 * HW2: Metro Simulator 
 * cs15
 * PassengerQueue.h
 * Caroline Chin 
 * 10/13/2021
 * Implementation of PassengerQueue Interface. Includes functions to manipulate 
 * PassengerQueue vector and includes a print function.
 */

#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__

#include <iostream>
#include "Passenger.h"
#include <vector>
using namespace std;

class PassengerQueue
{
public: 
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(ostream &output);
    Passenger at(int i);

private: 
        vector<Passenger> queue;
};
#endif

