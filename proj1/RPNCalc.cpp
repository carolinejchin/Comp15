/*
 * Proj1 CalcYouLater
 * cs15
 * RPNCalc.cpp
 * Caroline Chin 
 * 10/21/2021
 * Implementation of RPNCalc class 
 */


#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include "parser.cpp"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/*    Default Constructor 
 *    Purpose: vector class already has constructors 
 *               and destructors so RPNCalc does not 
 *               need a constructor
 *    Parameters: none 
 */
RPNCalc::RPNCalc() {
    
}

/*    Destructor 
 *    Purpose: vector class already has constructors 
 *               and destructors so RPNCalc does not 
 *               need a destructor
 *    Parameters: none 
 */
RPNCalc::~RPNCalc() {

}

/*    run 
 *    Purpose: calls the run function that takes in 
 *               commands and prints message when 
 *               calculator is done
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::run() {
    run(cin);
    cerr << "Thank you for using CalcYouLater." << endl;
}

/*    run 
 *    Purpose: calls the appropriate functions 
 *               depending on given command 
 *    Parameters: istream input, any istream 
 *    Returns: none
 */
void RPNCalc::run(istream &input) {
    string command;
    bool cont = true;
    while (cont == true && input >> command) {
        if (command[0] >= 48 && command[0] <= 57) {
            addingInt(command);
        }
        else if (command == "#t") {
            addingTrue();
        }

        else if (command == "#f") {
            addingFalse();
        }

        else if (command == "not") {
            notComparison();
        }

        else if (command == "print") {
            print();
        }

        else if (command == "clear") {
            stack.clear();     
        }

        else if (command == "drop") {
            dropElem();
        }

        else if (command == "dup") {
            duplicate();
        }

        else if (command == "swap") {
            swap();
        }

        else if (command == "quit") {
            cont = false;
        }

        else if (command == "+") {
            add();
        }

        else if (command == "-") {
            subtract();
        }

        else if (command == "*") {
            multiply(); 
        }

        else if (command == "/") {
            divide();
        }

        else if (command == "mod") {
            modular();
        }

        else if (command == "<") {
            lessThan();
        }

        else if (command == ">") {
            greaterThan();
        }

        else if (command == "<=") {
            lessThanEqual();
        }

        else if (command == ">=") {
            greaterThanEqual();
        }
    
        else if (command == "==") {
            equal();
        }

        else if (command[0] == 123) {
            string r = parseRString(input);
            Datum str = Datum(r);
            stack.push(str);
        }

        //used for exec b/c exec runs close brackets
        //through the command loop and says unimplemented
        else if (command == "}") {
    
        }

        else if(command == "exec") {
            exec();
        }

        else if (command == "file") {
            file();
        }
        
        else if (command == "if") {
            ifFunction();
        }
        
        else {
            cerr << command << ": unimplemented" << endl;
        }
    } 
}

/*    addingInt 
 *    Purpose: adds a Datum with given int to the stack 
 *    Parameters: string command which should be 
 *                  a number 
 *    Returns: none
 */
void RPNCalc::addingInt(string c) {
    Datum num = Datum(stoi(c));
    stack.push(num);
}

/*    addingTrue
 *    Purpose: adds a Datum with value true to the stack 
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::addingTrue() {
    Datum t = Datum(true);
    stack.push(t);
}    

/*    addingFalse
 *    Purpose: adds a Datum with value False to the stack 
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::addingFalse() {
    Datum f (false);
    stack.push(f);
}

/*    notComparison
 *    Purpose: pops the first Datum off the stack
 *          it should be a bool, and adds a datum of
 *          the opposite value
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::notComparison() {
    Datum top = Datum(0);
    try{
        top = stack.top();
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
    try{
        if (top.getBool() == false) {
            stack.push(Datum(true)); 
        }
    
        else {
            stack.push(Datum(false));
        }
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_bool" << endl;
        return;
    }

}

/*    print
 *    Purpose: prints the value of the top Datum of the stack 
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::print() {
    try {
        if (stack.top().isBool()) {
            if (stack.top().getBool()) {
                cout << "#t" << endl;
            }
            else {
                cout << "#f" << endl;
            }
        }
        else if (stack.top().isInt()) {
            cout << stack.top().getInt() << endl;
        }
        else {
            cout << stack.top().getRString() << endl;
        }
    }

    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
}

/*    dropElem
 *    Purpose: removes the top Datum from the stack 
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::dropElem() {
    try {
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
}

/*    duplicate
 *    Purpose: duplicates the top Datum of the DatumStack
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::duplicate() {
    try {
        Datum dup = stack.top();
        stack.push(dup);
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
}

/*    swap
 *    Purpose: swaps the top two elements in the DatumStack
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::swap() {
    try {
        Datum top1 = stack.top(); 
        stack.pop();
        Datum top2 = stack.top();
        stack.pop();
        stack.push(top1);
        stack.push(top2);
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
}

/*    add
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with the value of their sum
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::add() {
    Datum one(0);
    Datum two(0);
        try {
            one = stack.top();
            stack.pop();
            two = stack.top();
            stack.pop();
        }
        catch(runtime_error) {
            cerr << "Error: empty_stack" << endl;
            return;
        }
            
        try{
            int sum = two.getInt() + one.getInt();
            Datum d = Datum(sum);
            stack.push(d);
        }
        catch(runtime_error) {
            cerr << "Error: datum_not_int" << endl;
            return;
        }
}

/*    subtract
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with the value of their difference
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::subtract() {
    Datum one(0);
    Datum two(0);
    try {
        one = stack.top();
        stack.pop();
        two = stack.top();
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    try {
        int difference = two.getInt() - one.getInt();
        Datum d = Datum(difference);
        stack.push(d);
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_int" << endl;
        return;
    }
}

/*    multiply
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with the value of their product
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::multiply() {
    Datum one(0);
    Datum two(0);
    try {
        one = stack.top();
        stack.pop();
        two = stack.top();
        stack.pop();
                
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    try {
        int product = one.getInt() * two.getInt();
        Datum d = Datum(product);
        stack.push(d);
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_int" << endl;
        return;
    }
}

/*    divide
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with the value of their quotient
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::divide() {
    Datum one(0);
    Datum two(0);
    try {
        one = stack.top();
        stack.pop();
        two = stack.top();
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
    int x, y;
    try {
        x = one.getInt();
        y = two.getInt();
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_int" << endl;
        return;
    }
    if (x != 0) {
        int quotient = y / x;
        Datum d = Datum(quotient);
        stack.push(d);
    }
    else{
        cerr << "Error: division by 0." << endl;
    }
}

/*    mod
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with the value of their mod result
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::modular() {
    Datum one(0);
    Datum two(0);
    try {
        one = stack.top();
        stack.pop();
        two = stack.top();
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
    int x, y;
    try {
        x = one.getInt();
        y = two.getInt();
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_int" << endl;
        return;
    }
    if (x != 0) {
        int quotient = y % x;
        Datum d = Datum(quotient);
        stack.push(d);
    }
    else{
        cerr << "Error: division by 0." << endl;
    }
}

/*    lessThan
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with value true if Datum deeper
 *              in the stack is less than the other
 *              and vice versa
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::lessThan() {
    Datum one(0);
    Datum two(0);
    try {
        one = stack.top();
        stack.pop();
        two = stack.top();
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    try {
        if (two.getInt() < one.getInt()) {
            stack.push(Datum(true));
        }
                
        else {
            stack.push(Datum(false));
        }
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_int" << endl;
        return;
    }
}

/*    greaterThan
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with value true if Datum deeper
 *              in the stack is greater than the other
 *              and vice versa
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::greaterThan() {
        Datum one(0);
    Datum two(0);
    try {
        one = stack.top();
        stack.pop();
        two = stack.top();
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    try {
        if (two.getInt() > one.getInt()) {
            stack.push(Datum(true));
        }
                
        else {
            stack.push(Datum(false));
        }
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_int" << endl;
        return;
    }
}

/*    lessThanEqual
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with value true if Datum deeper
 *              in the stack is less than or equal
 *              to the other and vice versa
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::lessThanEqual() {
        Datum one(0);
    Datum two(0);
    try {
        one = stack.top();
        stack.pop();
        two = stack.top();
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    try {
        if (two.getInt() <= one.getInt()) {
            stack.push(Datum(true));
        }
                
        else {
            stack.push(Datum(false));
        }
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_int" << endl;
        return;
    }
}

/*    greaterThanEqual
 *    Purpose: pops the top two ints off
 *              the stack and adds a Datum
 *              with value true if Datum deeper
 *              in the stack is greater than or 
 *              equal to the other and vice versa
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::greaterThanEqual() {
        Datum one(0);
    Datum two(0);
    try {
        one = stack.top();
        stack.pop();
        two = stack.top();
        stack.pop();
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    try {
        if (two.getInt() >= one.getInt()) {
            stack.push(Datum(true));
        }
                
        else {
            stack.push(Datum(false));
        }
    }
    catch(runtime_error) {
        cerr << "Error: datum_not_int" << endl;
        return;
    }
}

/*    equal
 *    Purpose: pops the top two elems off
 *              the stack and adds a Datum
 *              with value true if the two
 *              Datums are equal
 *    Parameters: none 
 *    Returns: none
 */
void RPNCalc::equal() {
            Datum one(0);
            Datum two(0);
            try {
                one = stack.top();
                stack.pop();
                two = stack.top();
                stack.pop();
            }
            catch(runtime_error) {
                cerr << "Error: empty_stack" << endl;
                return;
            }

            if(one.isInt() && two.isInt()) {
                intEqual(one, two);
            }
            else if(one.isBool() && two.isBool()) {
                boolEqual(one, two);
            }
            else if(one.isRString() && two.isRString()) {
                rStringEqual(one, two);
            }
            else {
                stack.push(Datum(false));
            }
}

/*    intEqual
 *    Purpose: helper function of equal,
 *             checks if two ints are equal
 *    Parameters: Top two Datums that were 
 *                removed from the stack
 *    Returns: none
 */
void RPNCalc::intEqual(Datum o, Datum t) {
    if (o.isInt() && t.isInt()) {
        if (t.getInt() == o.getInt()) {
            stack.push(Datum(true));
        }
        
        else {
            stack.push(Datum(false));
        }
    }
}

/*    boolEqual
 *    Purpose: helper function of equal,
 *             checks if two bools are equal
 *    Parameters: Top two Datums that were 
 *                removed from the stack
 *    Returns: none
 */
void RPNCalc::boolEqual(Datum o, Datum t) {
    if (o.isBool() && t.isBool()){
        if (o.getBool() == t.getBool()) {
            stack.push(Datum(true));
        }
        
        else {
            stack.push(Datum(false));
        }
    }
}

/*    rStringEqual
 *    Purpose: helper function of equal,
 *             checks if two rstrings are equal
 *    Parameters: Top two Datums that were 
 *                removed from the stack
 *    Returns: none
 */
void RPNCalc::rStringEqual(Datum o, Datum t) {
    if (o.isRString() && t.isRString()) {
        if (o.getRString() == t.getRString()) {
            stack.push(Datum(true));
        }
        
        else {
            stack.push(Datum(false));
        }
    }
}

/*    exec
 *    Purpose: removes rstring from top of stack
 *             evaluates it, then adds a Datum of
 *             that value to the stack
 *    Parameters: none
 *    Returns: none
 */
void RPNCalc::exec() {
    try {
        if (stack.top().isRString() == false) {
            stack.pop();
            cerr << "Error: cannot execute non rstring" << endl;
        }

        else {
            string rstring = stack.top().getRString();
            stack.pop();
            stringstream s(rstring);
            string c;

            while (s >> c) {
                run(s);
            }
        }
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
}

/*    file
 *    Purpose: removes rstring with file name
 *             from top of stack, opens the file
 *             and runs the commands in the file
 *    Parameters: none
 *    Returns: none
 */
void RPNCalc::file() {
    try{
        if (stack.top().isRString() == false) {
            cerr << "Error: file operand not rstring" << endl;
        }

        else {
            fstream input2;
            string str;
            string file = stack.top().getRString();
            for (int i = 2; i < (int)file.size() - 2; i++) {
                str += file[i];
            }

            input2.open(str);
            if (not input2.is_open()) {
                cerr << "Unable to read " << str << endl;
            }
            stack.pop();
            run(input2);
        }
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
}

/*    if
 *    Purpose: removes three Datums from the stack
 *             two rstrings and a bool. If the bool
 *             is true, the second rstring is evaluated
 *             but if the bool is false the first rstring 
 *             is evaulated.
 *    Parameters: none
 *    Returns: none
 */
void RPNCalc::ifFunction() {
    //rstrings
    Datum falseCase(0);
    Datum trueCase(0);
    //bool
    Datum condition(0);
    try {
        falseCase = stack.top();
        stack.pop();
        trueCase = stack.top();
        stack.pop();
        condition = stack.top();
        stack.pop();
        if (condition.isBool()) {
            if (!falseCase.isRString() || !trueCase.isRString()) {
                cerr << "Error: expected rstring in if branch" << endl;
            }
            else {
                
            }
        }
        
        else {
            cerr << "Error: expected boolean in if test" << endl;
        }
    }
    catch(runtime_error) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    try{
        if (condition.getBool()) {
            stack.push(trueCase);
        }
        else {
            stack.push(falseCase);
        }
    }
    catch(runtime_error) {
        return;
    }
    exec();
}