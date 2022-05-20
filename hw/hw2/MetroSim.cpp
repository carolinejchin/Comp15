/*
 * HW2: Metro Simulator 
 * cs15
 * MetroSim.cpp
 * Caroline Chin 
 * 10/13/2021
 * Implementation of MetroSim class. Reads in station file, runs command loop 
 * and includes functions to assist in executing commands.
 */

#include "MetroSim.h"
#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

/*   
 *    Purpose: initializes MetroSim simulation, populates station_list and train 
 *    Parameters: input file 
 *    Returns: none
 */
MetroSim::MetroSim(ifstream &input) {
    string line;        
    Station enter;
    //fills station_list with stations 
    while (not input.eof()) {
        getline(input, line);
        enter.id = num_stations;
        enter.name = line;
        station_list.push_back(enter);
        num_stations++;
    }
    //initialize train vector
    train.resize(num_stations);
}

/*    run_command_loop
 *    Purpose: takes in commands and calls appropriate functions based on said
 *              commands
 *    Parameters: input and output file  
 *    Returns: none
 */
void MetroSim::run_command_loop(istream &input, ostream &output) {
    string command1, command2;
    int command3;
    cout << "Command? ";
    input >> command1;
    while (!done and not input.eof()) {
        //inserts new passenger 
        if (command1 == "p") {
            int int_command2;
            input >> int_command2 >> command3;
            add_passenger(int_command2, command3);
            print_status();
            cout << "Command? ";
            input >> command1;
        }
        else {
            input >> command2;
        }
        //move
        if (command1 == "m" and command2 == "m") {
            move(output);
            print_status();
            cout << "Command? ";
            input >> command1;
        } 
        //finish
        else if(command1 == "m" and command2 == "f") {
            done = true;
        }
    }
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl; 
}

/*    print_status
 *    Purpose: prints passengers on the train, list of stations and their 
 *             passengers, shows which station the train is at
 *    Parameters: none 
 *    Returns: none
 */
void MetroSim::print_status() {
    //train contents
    cout << "Passengers on the train: {";
    for (int i = 0; i < (int)train.size(); i++) {
        train.at(i).print(cout);
    }
    cout << "}" << endl;
    //station contents plus train location
    for (int k = 0; k < num_stations - 2; k++) {
        if (train_index == k + 1) {
            cout << "TRAIN: [" << k + 1 << "] " << station_list.at(k).name 
                << "{";
        }
        else {
            cout << "       [" << k + 1 << "] "<<  
            station_list.at(k).name << "{";
        }
        station_list.at(k).queue.print(cout);
        cout << "}" << endl;
    }
}

/*    add_passenger
 *    Purpose: Assigns given passenger appropriate id and adds them to 
 *             corresponding station passenger queue 
 *    Parameters: int arrival and departure from train  
 *    Returns: none
 */
void MetroSim::add_passenger(int arrival, int departure) {
    //creates new passenger with passenger constructor
    Passenger new_passenger(passenger_index, arrival, departure);
    //adds to appropriate station 
    station_list.at(arrival - 1).queue.enqueue(new_passenger);
    //increments number of passengers so id is in numerical order
    passenger_index++;
}

/*    depart_train
 *    Purpose: Removes passengers from train when the train is at the depature
 *             station and prints message to output file about passenger
 *             and dequeues pasengers from the train 
 *    Parameters: output file 
 *    Returns: none
 *    Note: is called in move 
 */
void MetroSim::depart_train(ostream &output) {
    //loops through train car passenger queue 
    int i = 0;
    while (train.at(train_index - 1).size()) {
        output << "Passenger " << train.at(train_index - 1).at(0).id << " left " 
                << "train at station " << station_list.at(train_index - 1).name 
                << endl;
        train.at(train_index - 1).dequeue();
        i++;
    }
}

/*    board_train
 *    Purpose: moves passenger from station to appropriate train queue/car 
 *             and dequeues passenger from station 
 *    Parameters: passenger 
 *    Returns: none
 *    Note: is called in move 
 */
void MetroSim::board_train(Passenger p) {
    //adds to appropriate train car/queue 
    train.at(p.to - 1).enqueue(p);
    //dequeue from station 
    station_list.at(train_index - 1).queue.dequeue();
}

/*    move 
 *    Purpose: moves passengers to the train from the station, moves the train 
 *             one station, lets passengers off the train
 *    Parameters: none 
 *    Returns: none
 */
void MetroSim::move(ostream &output) {
    //moving passengers onto train
     int size = station_list.at(train_index - 1).queue.size();
    for (int i = 0; i < size; i++) {
        board_train(station_list.at(train_index - 1).queue.at(0));
    }
    
    //move train
    int z = train_index;
    int c = station_list.size()- 1;
    if (z == c) {
        train_index = 1;
    }
    else {
        train_index++;
    }
    
    //passengers leave the train 
    depart_train(output);
}


