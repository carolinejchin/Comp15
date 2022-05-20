/*
 * Proj1 CalcYouLater
 * cs15
 * DatumStack.h
 * Caroline Chin 
 * 10/21/2021
 * Implementation of DatumStack Interface. Includes functions to manipulate 
 * stack of Datum which is a vector
 */
 
 #ifndef _DATUMSTACK_H_
 #define _DATUMSTACK_H_
 
 #include "Datum.h"
 #include <vector>
 using namespace std;
 
 class DatumStack {
    public:
        DatumStack();
        DatumStack(Datum arr[], int size); 
        
        bool isEmpty();
        void clear();
        int size();
        Datum top();
        void pop();
        void push(Datum d);
        
    private:
        vector<Datum> stack;      
 };
 #endif
 
 