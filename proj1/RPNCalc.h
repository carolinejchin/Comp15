/*
 * Proj1 CalcYouLater
 * cs15
 * RPNCalc.h
 * Caroline Chin 
 * 10/21/2021
 * Implementation of RPNCalc interface
 */


#ifndef _RPNCALC_H_
#define _RPNCALC_H_

#include "Datum.h"
#include "DatumStack.h"
//#include "parser.cpp"

 class RPNCalc {
    public:
        RPNCalc();
        ~RPNCalc(); 
        void run();
        
    private:
        DatumStack stack;
        void run(istream &ifstream);
        
        //helper functions
        void addingInt(string c);
        void addingTrue();
        void addingFalse();
        void notComparison();
        void print();
        void dropElem();
        void duplicate();
        void exec();
        void swap();
        void add();
        void subtract();
        void multiply();
        void divide();
        void modular();
        void lessThan();
        void greaterThan();
        void lessThanEqual();
        void greaterThanEqual();
        void equal();
        void intEqual(Datum o, Datum t);
        void boolEqual(Datum o, Datum t);   
        void rStringEqual(Datum o, Datum t);
        void file();
        void ifFunction();
 };
 #endif