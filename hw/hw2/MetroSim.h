/*
 * HW2: Metro Simulator 
 * cs15
 * MetroSim.h
 * Caroline Chin 
 * 10/13/2021
 * Implementation of MetroSim Interface. Includes add passenger, move, and 
 * helper functions. Stores necessary private values and also includes public
 * contructor and run_command_loop function to be accessed by outside files.
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"

// Put any other necessary includes here
#include "PassengerQueue.h"

// Put any other structs you need here

class MetroSim
{
public: 
        MetroSim(ifstream &input);
        void run_command_loop(istream &input, ostream &output);

private:
    int num_stations = 1;
    //keeps track of number of passengers/passenger indexing 
    int passenger_index = 1;
    bool done = false;
    void print_status();
    void add_passenger(int arrival, int depature);
    void depart_train(ostream &output);
    void board_train(Passenger p);
    void move(ostream &output);
    struct Station {
        int id;
        string name;
        PassengerQueue queue;
    };
        
    vector<Station> station_list;
        
    int train_index = 1;
    vector<PassengerQueue> train;
};

#endif
