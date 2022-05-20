/*
 * HW2: Metro Simulator 
 * cs15
 * unit_tests.h.h
 * Caroline Chin 
 * 10/13/2021
 * Unit testing for PassengerQueue
 */

#include <cassert>
#include <iostream>
#include "PassengerQueue.h"
#include "Passenger.h"
#include <vector>

void front_test() {
    PassengerQueue x;
    Passenger one(1, 1, 4);
    x.enqueue(one);
    Passenger two(2, 3, 6);
    x.enqueue(two);
    x.front().print(cout);
    x.dequeue();
    x.front().print(cout);
    
    //causes expected error
    // PassengerQueue y;
    // y.front();
}

void dequeue_test() {
    PassengerQueue x;
    Passenger one(1, 1, 4);
    x.enqueue(one);
    Passenger two(2, 3, 6);
    x.enqueue(two);
    x.dequeue();
    assert(x.size() == 1);
    x.print(cout);
    
    //causes expected error
    // PassengerQueue y;
    // y.dequeue();
}

void enqueue_test() {
    PassengerQueue x;
    assert(x.size() == 0);
    Passenger one(1, 8, 15);
    x.enqueue(one);
    assert(x.size() == 1);
    
    Passenger two(2, 5, 10);
    x.enqueue(two);
    assert(x.size() == 2);
    x.print(cout);
}

void size_test() {
    PassengerQueue x;
    assert(x.size() == 0);
    Passenger one(1, 8, 15);
    x.enqueue(one);
    assert(x.size() == 1);
    Passenger two(2, 3, 6);
    x.enqueue(two);
    assert(x.size() == 2);
}

void print_test() {
    PassengerQueue x;
    x.print(cout);
    Passenger one(1, 2, 18);
    x.enqueue(one);
    Passenger three(3, 8 ,4);
    x.enqueue(three);
    Passenger two(2, 3, 1);
    x.enqueue(two);
    x.print(cout);    
}

