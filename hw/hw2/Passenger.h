/*
 * HW2: Metro Simulator 
 * cs15
 * Passenger.h
 * Caroline Chin 
 * 10/13/2021
 * One implementation of Passenger Interface. Includes two contructors for Passenger
 * struct and includes a print function.
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

    int id, from, to;
        
    Passenger()
    {
        id   = -1;
        from = -1;
        to   = -1;
    }

    Passenger(int newId, int arrivalStation, int departureStation)
    {
        id   = newId;
        from = arrivalStation;
        to   = departureStation;
    }

    void print(std::ostream &output);
};

#endif
