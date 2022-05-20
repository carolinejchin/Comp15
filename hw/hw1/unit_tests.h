/* 
 * unit_tests.h
 * 
 * CS 15 homework 1
 * by C.R. Calabrese, January 2021
 * 
 * Uses Matt Russell's unit_test framework to test the CharArrayList and
 * CharLinkedList.
 * More information on this testing framework can be found in the Lab 1
 * handout
 */

#include <cassert>
#include "CharArrayList.h"
#include "CharLinkedList.h"
#include <iostream>


/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* default constructor test
 * Run the ArrayList default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_AL()
{
    CharArrayList testArrayList;
    assert(testArrayList.size() == 0);
    testArrayList.print();
}

/* constructor test 1
 *    Purpose: Runs the first constructor and checks if a one element array list
 *    was created
 *    Parameters: none
 *    Returns: Nothing
 */
void constructor_AL()
{
    CharArrayList testArrayList('f');
    assert(testArrayList.size() == 1);
    assert(testArrayList.elementAt(0) == 'f');
    testArrayList.print();
}
/* constructor test 2
 *    Purpose: Runs the second constructor and checks that an array list with   
 *    elements from the given array was constructed
 *    Parameters: none
 *    Returns: Nothing
 * 
 */
void constructor_AL_2()
{
    char letters [3]= {'a', 'b', 'c'};
    CharArrayList testArrayList(letters, 3);
    testArrayList.print();
    assert(testArrayList.size() == 3);
    assert(testArrayList.elementAt(2) == 'c');
    testArrayList.print();

    char sequence[7] = {'m', 'v', 'x', 'e', 'i', 'g', 'z'};
    CharLinkedList testArrayList2(sequence, 7);
    assert(testArrayList2.size() == 7);
    assert(testArrayList2.last() == 'z');
    testArrayList2.print();
}
/* isEmpty test 
 *    Purpose: Runs the isEmpty function on an empty array, an array with one 
 *    char and an array with multiple chars and tests if the function returns  
 *    the correct boolean value
 *    Parameters: none
 *    Returns: Nothing
 */
void emptyTest_AL()
{
    CharArrayList testArrayList('k');
    assert(testArrayList.isEmpty() == false);

    CharArrayList testArrayList1;
    assert(testArrayList1.isEmpty() == true);

    char letters [3]= {'p', 'j', 'd'};
    CharArrayList testArrayList2(letters, 3);
    assert(testArrayList2.isEmpty() == false);
}

/* size test 
 *    Purpose: Tests the size function on arrays of varying sizes and makes 
 *    makes sure the correct size is returned
 *    Parameters: none
 *    Returns: Nothing
 */
void sizeTest_AL()
{
    CharArrayList testArrayList('l');
    assert(testArrayList.size() == 1);

    CharArrayList testArrayList1;
    assert(testArrayList1.size() == 0);

    char letters [5]= {'a', 'b', 'c', 'l', 'f'};
    CharArrayList testArrayList2(letters, 5);
    assert(testArrayList2.size() == 5);
}

/* first test 
 *    Purpose: Runs the first function on arrays of varying size to make sure 
 *    it always returns the first element unless ArrayList is empty
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
void firstTest_AL()
{
    CharArrayList testArrayList('b');
    assert(testArrayList.first() == 'b');

    char letters [4]= {'x', 'm', 't', 'r'};
    CharArrayList testArrayList1(letters, 4);
    assert(testArrayList1.first() == 'x');

    //causes expected error
    // CharArrayList testArrayList2;
    // testArrayList2.first();
}

/* last test 
*    Purpose: Runs the last function on arrays of varying size to make sure 
*    it always returns the last element unless ArrayList is empty
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
void lastTest_AL() {
    CharArrayList testArrayList('b');
    assert(testArrayList.last() == 'b');

    char letters [4]= {'x', 'm', 't', 'r'};
    CharArrayList testArrayList1(letters, 4);
    assert(testArrayList1.last() == 'r');

    //causes expected error
    // CharArrayList testArrayList2;
    // testArrayList2.last();
}

/* elementAt test 
 *    Purpose: Runs the elementAt function on arraylists of various sizes and 
 *    at various indexes to make sure the correct value is returned
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty or idx is out of 
 *       bounds.
 */
 
void elementAtTest_AL() {
    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList testArrayList(letters, 5);
    assert(testArrayList.elementAt(0) == 'a');
    assert(testArrayList.elementAt(3) == 'd');
    assert(testArrayList.elementAt(4) == 'e');
    //causes expected error
    //testArrayList.elementAt(999);
    //testArrayList.elementAt(-5);

    CharArrayList testArrayList2('k');
    assert(testArrayList2.elementAt(0) == 'k');
    //causes expected error 
    // assert(testArrayList2.elementAt(1) == 'k');
    // testArrayList2.clear();
    // testArrayList2.elementAt(0) == 'k';
}

/* print test 
 *    Purpose: Runs the print function on arrays of varying size to check if
 *    array lists are being printed correctly
 *    Parameters: none
 *    Returns: Nothing
 */
void printTest_AL() {
    CharArrayList testArrayList;
    testArrayList.print();

    CharArrayList testArrayList1('b');
    testArrayList1.print();

    char array [9] = {'j', 'c', 'p', 'i', 'k', 'r', 'k', 'f', 's'};
    CharArrayList testArrayList2(array, 9);
    testArrayList2.print();
}

/* clear test 
 *    Purpose: Run the clear function on array lists of varying sizes and tests 
 *    if they're empty and the length is equal to zero
 *    Parameters: none
 *    Returns: Nothing
 */
void clearTest_AL() {
    CharArrayList testArrayList;
    testArrayList.clear();
    assert(testArrayList.isEmpty());
    testArrayList.print();

    testArrayList.pushAtFront('f');
    testArrayList.clear();
    assert(testArrayList.size() == 0);
    testArrayList.print();

    char letters [6]= {'k', 'd', 'a', 'v', 'z', 'i'};
    CharArrayList testArrayList2(letters, 6);
    testArrayList2.clear();
    assert(testArrayList2.isEmpty());
    testArrayList2.print();
}

/* pushAtBack test 
 *    Purpose: Runs the pushAtBack on different sized ArrayLists and checks if 
 *    the given char was added to the back of the array list 
 *    Parameters: none
 *    Returns: Nothing
 */
void pushAtBackTest_AL()
{
    CharArrayList testArrayList('a');
    testArrayList.pushAtBack('c');
    assert(testArrayList.last() == 'c');
    assert(testArrayList.first() == 'a');
    testArrayList.print();

    char letters [6]= {'k', 'd', 'a', 'v', 'z', 'i'};
    CharArrayList testArrayList1(letters, 6);
    testArrayList1.pushAtBack('l');
    assert(testArrayList1.last() == 'l');
    assert(testArrayList1.elementAt(3) == 'v');
    testArrayList1.print();

    CharArrayList testArrayList2;
    testArrayList2.pushAtBack('q');
    assert(testArrayList2.last() == 'q');
    assert(testArrayList2.size() == 1);
    testArrayList2.print();
}
/* pushAtFront test 
 *    Purpose: Runs the pushAtFront on different sized ArrayLists and checks if 
 *    the given char was added to the front of the array list 
 *    Parameters: none
 *    Returns: Nothing
 */
void pushAtFrontTest_AL()
{
    CharArrayList testArrayList2;
    testArrayList2.pushAtFront('u');
    assert(testArrayList2.first() == 'u');
    testArrayList2.print();

    CharArrayList testArrayList1('o');
    testArrayList1.pushAtFront('h');
    assert(testArrayList1.first() == 'h');
    testArrayList1.print();

    char letters [3]= {'a', 'b', 'c'};
    CharArrayList testArrayList(letters, 3);
    testArrayList.pushAtFront('f');
    assert(testArrayList.first() == 'f');
    assert(testArrayList.size() == 4);
    testArrayList.print();
}
/* insertAt test 
 *    Purpose: Runs the insertAt test on arrays of varying size for various
 *    indexes testing if the proper elements were inserted
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if idx is out of 
 *       bounds.
 */
void insertAtTest_AL() 
{
    char letters [4]= {'a', 'b', 'd', 'e'};
    CharArrayList testArrayList(letters, 4);
    testArrayList.insertAt('c', 2);
    testArrayList.insertAt('x', 0);
    testArrayList.insertAt('f', 6);
    testArrayList.print();
    assert(testArrayList.elementAt(3) == 'c');
    assert(testArrayList.elementAt(0) == 'x');
    assert(testArrayList.elementAt(6) == 'f');

    //causes expected error 
    //testArrayList.insertAt('g', 8);
    //testArrayList.insertAt('r', -1);

    CharArrayList testArrayList1;
    //causes expected error 
    //testArrayList1.insertAt('u', 1);

    testArrayList1.insertAt('h', 0);

    //causes expected error 
    //testArrayList1.insertAt('f', -1);
}

/* popFromFront test 
 *    Purpose: Runs the popFromFront function on arrays of varying size to make
 *    sure it works correctly and prints error staements
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
void popFromFrontTest_AL() {
    CharArrayList testArrayList('l');
    testArrayList.popFromFront();
    testArrayList.print();

    //causes expected errors
    //testArrayList.popFromFront();

    char letters [3]= {'a', 'b', 'd'};
    CharArrayList testArrayList2(letters, 3);
    testArrayList2.popFromFront();
    testArrayList2.popFromFront();
    testArrayList2.popFromFront();
    testArrayList2.print();

    //causes expected error 
    //testArrayList2.popFromFront();
}

/* popFromBack test 
*     Purpose: Runs the popFromBack function on arrays of varying size to make
*     sure it works correctly and prints error staements
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
void popFromBackTest_AL() {
    CharArrayList testArrayList('l');
    testArrayList.popFromBack();
    testArrayList.print();

    //causes expected errors
    //testArrayList.popFromBack();

    char letters [3]= {'a', 'b', 'd'};
    CharArrayList testArrayList2(letters, 3);
    testArrayList2.popFromBack();
    testArrayList2.popFromBack();
    testArrayList2.popFromBack();
    testArrayList2.print();

    //causes expected error 
    //testArrayList2.popFromBack();
}
/* RemoveAt test 
 *    Purpose: Runs the removeAt function at various indexes of an array list
 *    and also checks indexes out of bounds and empty array lists. To test if
 *    the array list was shrinking, 6/8 elements were removed and a cerr 
 *    statement was written in the removeat function to see when it was 
 *    shrinking.
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if idx is out of 
 *       bounds.
 */
void removeAtTest_AL()
{
    char letters [8] = {'g', 'l', 'p', 'o', 'h', 'n', 'm', 'd'};
    CharArrayList testArrayList(letters, 8);
    //causes expected errors
    //testArrayList.removeAt(8);
    //testArrayList.removeAt(-4);

    testArrayList.removeAt(7);
    testArrayList.removeAt(0);
    testArrayList.removeAt(4);
    testArrayList.removeAt(2);
    testArrayList.print();
    testArrayList.removeAt(0);
    testArrayList.removeAt(0);
    testArrayList.removeAt(0);
    //shrunk once 

    //causes expected error 
    // CharArrayList testArrayList2;
    // testArrayList2.removeAt(0);
}
/* ReplaceAt test 
 *    Purpose: Runs the removeAt function at various indexes of an array list
 *    and also checks indexes out of bounds and empty array lists
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if idx is out of 
 *       bounds.
 */
void replaceAtTest_AL()
{
    char letters [4] = {'a', 'b', 'd', 'e'};
    CharArrayList testArrayList(letters, 4);
    testArrayList.replaceAt('l', 1);
    testArrayList.replaceAt('m', 0);
    testArrayList.replaceAt('c', 3);
    testArrayList.print();

    //causes expected errors
    //testArrayList.replaceAt('l', 4);
    //testArrayList.replaceAt('i', -8);
}

/* concatenate test 
 *    Purpose: Runs the concateneate function with different combinations of
 *    array lists, including empty ones to test the concatenate function
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if idx is out of 
 *       bounds.
 */
void concatenateTest_AL()
{
    char cat [3] = {'c', 'a', 't'};
    CharArrayList CharListOne(cat, 3);

    char cheshire [8] = {'C', 'H', 'E', 'S', 'H', 'I', 'R', 'E'};
    CharArrayList CharListTwo(cheshire, 8);

    CharListOne.concatenate(CharListTwo);
    CharListOne.print();
    assert(CharListOne.size() == 11);

    CharListTwo.concatenate(CharListTwo);
    CharListTwo.print();
    assert(CharListTwo.size() == 16);

    CharArrayList empty;
    CharListTwo.concatenate(empty);
    CharListTwo.print();
    assert(CharListTwo.size() == 16);

    empty.concatenate(CharListOne);
    empty.print();
    assert(empty.size() == 11);
}




/*******************************************************************\
*                      CHAR LINKED LIST TESTS                       *
\*******************************************************************/

/* default constructor test
 * Run the LinkedList default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_LL()
{
    CharLinkedList testLinkedList;
    testLinkedList.print();
    assert(testLinkedList.isEmpty());
    assert(testLinkedList.size() == 0);
}

/* constructor test 1
 *    Purpose: Runs the first constructor which creates a linked list with one 
 *    char
 *    Parameters: none
 *    Returns: Nothing
 */
void constructor_LL()
{
    CharLinkedList testLinkedList('h');
    assert(testLinkedList.isEmpty() == false);
    assert(testLinkedList.size() == 1);
    testLinkedList.print();
}

/* constructor test 2
 *    Purpose: Runs the first constructor which creates a linked list with the
 *    given array and given size. tested with various linked list sizes 
 *    Parameters: none
 *    Returns: Nothing
 */
void constructor_LL_2() {
    char letters [5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList testLinkedList(letters, 5);
    testLinkedList.print();
    assert(testLinkedList.elementAt(2) == 'c');

    char sequence [1] = {'k'};
    CharLinkedList testLinkedList2(sequence, 1);
    testLinkedList2.print();
    assert(testLinkedList2.size() == 1);

    char empty [0] = {};
    CharLinkedList testLinkedList3(empty, 0);
    testLinkedList3.print();
    assert(testLinkedList3.size() == 0);
}

/* copy constructor test 
 *    Purpose: creates two linked lists and uses the copy constructor to make 
 *    the linked list it is being called on contain the same elements as the  
 *    parameter entered, if the two are equal after the copy construtor is 
 *    called, the copy constructor works. tests for different sized linked 
 *    lists
 *    Parameters: none
 *    Returns: Nothing
 */
void copy_constructor_test_LL() {
    CharLinkedList testLinkedList('l');
    CharLinkedList testLinkedList2(testLinkedList);
    testLinkedList2.print();
    
    char letters[3] = {'a', 'b', 'c'};
    CharLinkedList testLinkedList3(letters, 3);
    CharLinkedList testLinkedList4(testLinkedList3);
    assert(testLinkedList4.size() == testLinkedList3.size());
    testLinkedList4.print();

    CharLinkedList testLinkedList5;
    CharLinkedList testLinkedList6(testLinkedList5);
    testLinkedList6.print();    
}

/* assignment operator test 
 *    Purpose: creates two linked lists and uses the assignment operator to  
 *      make the lhs contain the same elements as the rhs, if the two are equal
 *      after the assignment operatoris called the assignment operator works 
 *    Parameters: none
 *    Returns: Nothing
 */
void operatorTest_LL() {
    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList testLinkedList(letters, 5);
    CharLinkedList testLinkedList2;
    testLinkedList2 = testLinkedList;
    assert(testLinkedList2.size() == 5);
    testLinkedList2.print();

    testLinkedList2.clear();
    testLinkedList = testLinkedList2;
    assert(testLinkedList.size() == 0);
    testLinkedList.print();
}

/* isEmpty test 
 *    Purpose: Runs the isEmpty function on an empty array, an array with one 
 *    char and an array with multiple chars and tests if the function returns  
 *    the correct boolean value
 *    Parameters: none
 *    Returns: Nothing
 */
void isEmptyTest_LL() {
    CharLinkedList testLinkedList;
    assert(testLinkedList.isEmpty() == true);
    //causes expected error
    //assert(testLinkedList.isEmpty() == false);

    CharLinkedList testLinkedList2('h');
    assert(testLinkedList2.isEmpty() == false);
    //causes expected error 
    //assert(testLinkedList2.isEmpty() == true);

    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList testLinkedList3(letters, 5);
    assert(testLinkedList3.isEmpty() == false);
    //causes expected error 
    //assert(testLinkedList3.isEmpty() == true);
}

/* size test 
 *    Purpose: Tests the size function on linked lists of varying sizes and 
 *    makes sure the correct size is returned
 *    Parameters: none
 *    Returns: Nothing
 */
void sizeTest_LL() {
    CharLinkedList testLinkedList('p');
    assert(testLinkedList.size() == 1);
    testLinkedList.popFromFront();
    testLinkedList.print();
    assert(testLinkedList.size() == 0);

    char list [8] = {'c', 'a', 'r', 'o', 'l', 'i', 'n', 'e'};
    CharLinkedList testLinkedList2(list, 8);
    assert(testLinkedList2.size() == 8);
}
/* first test 
 *    Purpose: Runs the first function on arrays of varying size to make sure 
 *    it always returns the first element unless ArrayList is empty
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
void firstTest_LL() {
    CharLinkedList testLinkedList('p');
    assert(testLinkedList.first() == 'p');
    testLinkedList.pushAtBack('k');
    assert(testLinkedList.first() == 'p');

    CharLinkedList testLinkedList2;
    //causes expected error 
    //testLinkedList2.first();

    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList testLinkedList3(letters, 5);
    assert(testLinkedList3.first() == 'a');
}

/* last test 
 *    Purpose: Runs the last function on arrays of varying size to make sure 
 *    it always returns the last element unless ArrayList is empty
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
void lastTest_LL() {
    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList testLinkedList(letters, 5);
    assert(testLinkedList.last() == 'e');

    CharLinkedList testLinkedList2('z');
    assert(testLinkedList2.last() == 'z');

    //causes expected errors
    //CharLinkedList testLinkedList3;
    //testLinkedList3.last();
}

/* elementAt test 
 *    Purpose: Runs the elementAt function on linked lists of various sizes and 
 *    at various indexes to make sure the correct value is returned
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty or idx is out of 
 *       bounds.
 */
void elementAtTest_LL() {
    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList testLinkedList(letters, 5);
    assert(testLinkedList.elementAt(0) == 'a');
    assert(testLinkedList.elementAt(3) == 'd');
    testLinkedList.print();
    //assert(testLinkedList.elementAt(4) == 'e');
    //causes expected error
    //testLinkedList.elementAt(-1);
    //testLinkedList.elementAt(6);

    CharLinkedList testLinkedList2('k');
    assert(testLinkedList2.elementAt(0) == 'k');
    testLinkedList2.print();
    //causes expected error 
    //testLinkedList2.elementAt(1);
    // testLinkedList2.clear();
    // testLinkedList2.elementAt(0);
}
/* print test 
 *    Purpose: Runs the print function on arrays of varying size to check if
 *    array lists are being printed correctly
 *    Parameters: none
 *    Returns: Nothing
 */
void printTest_LL() {
    char letters[6] = {'o', 'v', 'y', 't', 'w', 'n'};
    CharLinkedList testLinkedList(letters, 6);
    testLinkedList.print();

    CharLinkedList testLinkedList2('u');
    testLinkedList2.print();

    CharLinkedList testLinkedList3;
    testLinkedList3.print();
}
/* clear test 
 *    Purpose: Run the clear function on array lists of varying sizes and tests 
 *    if they're empty and the length is equal to zero
 *    Parameters: none
 *    Returns: Nothing
 */
void clearTest_LL() {
    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList testLinkedList(letters, 5);
    testLinkedList.clear();
    assert(testLinkedList.isEmpty());

    CharLinkedList testLinkedList2('n');
    testLinkedList2.clear();
    assert(testLinkedList2.isEmpty());

    CharLinkedList testLinkedList3;
    testLinkedList3.clear();
    assert(testLinkedList3.isEmpty());
}

/* pushAtBack test 
 *    Purpose: Runs the pushAtBack on different sized linked Lists and checks  
 *      if the given char was added to the back of the array list 
 *    Parameters: none
 *    Returns: Nothing
 */
void pushAtBackTest_LL()
{
    CharLinkedList testLinkedList('c');
    testLinkedList.pushAtBack('a');
    testLinkedList.pushAtBack('l');
    assert(testLinkedList.first() == 'c');
    assert(testLinkedList.last() == 'l');

    CharLinkedList testLinkedList2;
    testLinkedList2.pushAtBack('a');
    assert(testLinkedList2.first() == 'a');

    char letter [3] = {'l', 'f', 'r'};
    CharLinkedList testLinkedList3(letter, 3);
    testLinkedList3.pushAtBack('i');
    assert(testLinkedList3.last() == 'i');
}

/* pushAtFront test 
 *    Purpose: Runs the pushAtFront on different sized LinkedLists and checks  
 *      if the given char was added to the front of the array list 
 *    Parameters: none
 *    Returns: Nothing
 */
void pushAtFrontTest_LL() 
{
    CharLinkedList testLinkedList('r');
    testLinkedList.pushAtFront('a');
    testLinkedList.pushAtFront('c');
    assert(testLinkedList.size() == 3);
    assert(testLinkedList.first() == 'c');
    assert(testLinkedList.elementAt(2) == 'r');
    testLinkedList.print();

    CharLinkedList testLinkedList2;
    testLinkedList2.pushAtFront('r');
    testLinkedList2.print();
}

/* insertAt test 
 *    Purpose: Runs the insertAt test on linked lists of varying size for 
 *      various indexes testing if the proper elements were inserted
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if idx is out of 
 *       bounds.
 */
void insertAtTest_LL() 
{
    CharLinkedList testLinkedList('r');
    testLinkedList.insertAt('o', 1);
    testLinkedList.insertAt('l', 0);
    testLinkedList.insertAt('n', 3);
    testLinkedList.insertAt('i', 4);
    assert(testLinkedList.size() == 5);
    assert(testLinkedList.first() == 'l');
    assert(testLinkedList.last() == 'i');
    testLinkedList.print();

    //causes expected errors
    //testLinkedList.insertAt('p', -3);
    //testLinkedList.insertAt('k', 6);


    CharLinkedList testLinkedList2;
    // causes expected error 
    //testLinkedList2.insertAt('p', 1);
    testLinkedList2.insertAt('k', 0);
    testLinkedList2.insertAt('a', 1);
    assert(testLinkedList2.first() == 'k');
    testLinkedList2.print();
}

/* popFromFront test 
 *    Purpose: Runs the popFromFront function on lists of varying size to make
 *    sure it works correctly and prints error statements
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
void popFromFrontTest_LL() 
{
    //causes expected error
    //CharLinkedList testLinkedList3;
    //testLinkedList3.popFromFront();

    CharLinkedList testLinkedList2('f');
    testLinkedList2.popFromFront();
    testLinkedList2.print();

    char list[6] = {'k', 'a', 'c', 'h', 'o', 'w'};
    CharLinkedList testLinkedList(list, 6);
    testLinkedList.popFromFront();
    testLinkedList.print();
    assert(testLinkedList.size() == 5);
    assert(testLinkedList.first() == 'a');
}


/* popFromBack test 
*     Purpose: Runs the popFromBack function on lists of varying size to make
*     sure it adds elements to the back correctly and prints error statements
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
void popFromBackTest_LL() {
    CharArrayList testLinkedList('l');
    testLinkedList.popFromBack();
    testLinkedList.print();

    //causes expected errors
    //testLinkedList.popFromBack();

    char letters [3]= {'a', 'b', 'd'};
    CharArrayList testLinkedList2(letters, 3);
    testLinkedList2.popFromBack();
    testLinkedList2.popFromBack();
    testLinkedList2.popFromBack();
    testLinkedList2.print();

    //causes expected error 
    //testLinkedList2.popFromBack();
}

/* RemoveAt test 
 *    Purpose: Runs the removeAt function at various indexes of a linked list
 *    and also checks indexes out of bounds and empty linked lists. To test if
 *    the linked list was shrinking, 6/8 elements were removed and a cerr 
 *    statement was written in the removeat function to see when it was 
 *    shrinking.
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if idx is out of 
 *       bounds.
 */
void removeAtTest_LL()
{
    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList testLinkedList(letters, 5);
    testLinkedList.removeAt(4);
    testLinkedList.removeAt(0);
    testLinkedList.removeAt(1);
    testLinkedList.print();

    //causes expected errors
    //testLinkedList.removeAt(9);
    //testLinkedList.removeAt(-5);

    CharLinkedList testLinkedList2('g');
    testLinkedList2.removeAt(0);
    testLinkedList2.print();
    testLinkedList2.clear();
    //causes expected error 
    //testLinkedList2.removeAt(1);
    //testLinkedList2.removeAt(0);
}

/* ReplaceAt test 
 *    Purpose: Runs the removeAt function at various indexes of a linked list
 *    and also checks indexes out of bounds and empty linked lists
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if idx is out of 
 *       bounds.
 */
void replaceAtTest_LL() {
    char car[6] = {'x', 'a', 'c', 'x', 'o', 'x'};
    CharLinkedList testLinkedList(car, 6);
    testLinkedList.replaceAt('k', 0);
    testLinkedList.replaceAt('h', 3);
    testLinkedList.replaceAt('w', 5);
    assert(testLinkedList.elementAt(3) == 'h');
    testLinkedList.print();

    //causes expected errors
    //testLinkedList.replaceAt('j', -2);

    CharLinkedList testLinkedList2('d');
    testLinkedList2.replaceAt('w', 0);
    assert(testLinkedList2.first() == 'w');

    //causes expected error
    //testLinkedList2.replaceAt('a', 1);

    // CharLinkedList testLinkedList3;
    // testLinkedList3.replaceAt('f', 0);
}

/* concatenate test 
 *    Purpose: Runs the concateneate function with different combinations of
 *    linked lists, including empty ones to test the concatenate function
 *    Parameters: none
 *    Returns: Nothing
 * 
 *       Note: Prints an error and exits if idx is out of 
 *       bounds.
 */
void concatenateTest_LL() {
    char cat [3] = {'c', 'a', 't'};
    CharArrayList CharListOne(cat, 3);

    char cheshire [8] = {'C', 'H', 'E', 'S', 'H', 'I', 'R', 'E'};
    CharArrayList CharListTwo(cheshire, 8);

    CharListOne.concatenate(CharListTwo);
    CharListOne.print();
    assert(CharListOne.size() == 11);

    CharListTwo.concatenate(CharListTwo);
    CharListTwo.print();
    assert(CharListTwo.size() == 16);

    CharArrayList empty;
    CharListTwo.concatenate(empty);
    CharListTwo.print();
    assert(CharListTwo.size() == 16);

    empty.concatenate(CharListOne);
    empty.print();
    assert(empty.size() == 11);
}