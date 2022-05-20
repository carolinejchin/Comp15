/*
 * Proj1: CalcYouLater
 * cs15
 * unit_tests.h
 * Caroline Chin 
 * 10/21/2021
 * Unit testing for functions of DatumStack.cpp
 */

#include "DatumStack.h"
#include "Datum.h"
#include "parser.cpp"
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
using namespace std;
#include <string>

void default_constructor_test() {
    DatumStack testDatumStack;
    assert(testDatumStack.isEmpty() == true);
}

void constructor_test() {
    Datum test_array[3] = { Datum(5), Datum(true), Datum("hello") };
    DatumStack testDatumStack2(test_array, 3);
    assert(testDatumStack2.isEmpty() == false);
}

void isEmptyTest() {
    DatumStack testDatumStack3;
    assert(testDatumStack3.isEmpty() == true);   

    Datum test_array[5] = { Datum(17), Datum(false), 
        Datum(5), Datum(true), Datum("hello") };
    DatumStack testDatumStack4(test_array, 5);
    assert(testDatumStack4.isEmpty() == false);
}

void clearTest() {
    Datum test_array[5] = { Datum(17), Datum(false), 
        Datum(5), Datum(true), Datum("hello") };
    DatumStack testDatumStack5(test_array, 5);
    testDatumStack5.clear();
    assert(testDatumStack5.isEmpty() == true);

    DatumStack testDatumStack6;
    testDatumStack6.clear();
    assert(testDatumStack6.isEmpty() == true);  

    Datum test_arr[1] = {Datum(false)};
    DatumStack testDatumStack7(test_arr, 1);
    testDatumStack7.clear();
    assert(testDatumStack7.isEmpty() == true);
}

void sizeTest() {
    Datum test_array[6] = { Datum(17), Datum(false), Datum(5), 
        Datum(true), Datum("hello"), Datum("test") };
    DatumStack testDatumStack8(test_array, 6);
    assert(testDatumStack8.size() == 6);

    DatumStack testDatumStack9;
    assert(testDatumStack9.size() == 0);  

    Datum test_arr[1] = {Datum(false)};
    DatumStack testDatumStack10(test_arr, 1);
    assert(testDatumStack10.size() == 1);
}

void topTest() {
    //causes expected error
    // DatumStack testDatumStack;
    // testDatumStack.top();

    Datum test_array[5] = { Datum(17), Datum(false), 
        Datum(5), Datum(true), Datum("hello") };
    DatumStack testDatumStack2(test_array, 5);
    string test = testDatumStack2.top().toString();
    cout << test << endl;

    Datum arr[1] = {Datum("string")};
    DatumStack testDatumStack3(arr, 1);
    string test2 = testDatumStack3.top().toString();
    cout << test2 << endl;
}

void popTest() {
    //causes expected error
    // DatumStack testDatumStack;
    // testDatumStack.pop();

    Datum test_array[5] = { Datum(17), Datum(false), 
        Datum(5), Datum(true), Datum("hello") };
    DatumStack testDatumStack2(test_array, 5);
    testDatumStack2.pop();
    cout << "Size: " << testDatumStack2.size() << endl;
    assert(testDatumStack2.size() == 4);
    bool test = testDatumStack2.top().getBool();
    cout << test << endl;

    Datum test_arr[1] = {Datum(false)};
    DatumStack testDatumStack3(test_arr, 1);
    testDatumStack3.pop();
    assert(testDatumStack3.size() == 0);
    
}

void pushTest() {
    DatumStack testDatumStack;
    Datum d = Datum(84);
    testDatumStack.push(d);
    assert(testDatumStack.size() == 1);

    Datum test_array[5] = { Datum(17), Datum(false), 
        Datum(5), Datum(true), Datum("hello") };
    DatumStack testDatumStack2(test_array, 5);
    Datum temp = Datum("test");
    testDatumStack2.push(temp);
    assert(testDatumStack2.size() == 6);
}

