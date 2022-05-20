/* 
 * CharLinkedList.cpp
 * 
 * COMP 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by Caroline Chin, 9/23
 * 
 * Stores characters in a certain order. It imitates some functions of the
 * C++ string. 
 * 
 * NOTE: This is implemented using a doubly-linked list. It is not circular
 *       and does not have a "back" pointer.
 */

#include "CharLinkedList.h"

// for the print function
#include <iostream>

using namespace std;

/* Purpose: initializes an empty CharLinkedList */
CharLinkedList::CharLinkedList()
{
    front = nullptr;
    len = 0;
}

/*    Purpose: initializes a CharLinkedList containing one character
 * Parameters: the character that should be stored in the new list
 */
CharLinkedList::CharLinkedList(char c)
{
    Node *newNode = new Node;
    
    newNode->data = c;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    front = newNode;
    len = 1;
    
}

/*    Purpose: initializes a CharLinkedList containing all of the specified 
 *             characters, in the given order
 * Parameters: An array (in order) of characters to be stored in the list;
 *             the length of the given array (as an int)
 */
CharLinkedList::CharLinkedList(char *arr, int size)
{
    len = 0;
    front = nullptr;
    for (int i = 0; i < size; i++) {
        pushAtBack(arr[i]);
    }   
}

/* Purpose: copy constructor -- creates a list with the same information as
 *          the one passed in
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) 
{
    len = 0;
    front = nullptr;
    for (int i = 0; i < other.size(); i++) {
        pushAtBack(other.elementAt(i));
    }
    
    
}

/* Purpose: destructor -- frees all memory associated with the list */
CharLinkedList::~CharLinkedList()
{
    Node *del = front;
    while (del != nullptr) {
        front = front->next;
        delete del;
        del = front;
    }
}

/* Purpose: assignment operator -- makes the current list contain the same
 *          information as the one on the right hand side
 */
CharLinkedList &CharLinkedList::operator =(const CharLinkedList &rhs) 
{
    if (this != &rhs) {
        clear(); // clear the current list
        cerr<<"OPERATOR"<< endl;
        // add each element from the other list into this one
        for (int i = 0; i < rhs.size(); i++) {
            pushAtBack(rhs.elementAt(i));
        }
    }
    return *this;
}

/* isEmpty
 *    Purpose: Check if the list is empty
 * Parameters: none
 *    Returns: a boolean -- true if the list is empty, false if it isn't
 */
bool CharLinkedList::isEmpty() const 
{
    if (len != 0) {
        return false;
    }
    return true;
}

/* size
 *    Purpose: Get the number of characters being stored in the list
 * Parameters: none
 *    Returns: The number of characters currently stored in the list, as an
 *             int (will never be negative)
 */
int CharLinkedList::size() const 
{
    if (front == nullptr) {
        return 0;
    }
    Node *curr = front;
    int count = 1;
    while(curr->next != nullptr) {
        curr = curr->next;
        count++;
    }
    return count;
}

/* first
 *    Purpose: Get the first element in the list.
 * Parameters: none
 *    Returns: The first element in the list, as a char.
 * 
 *       Note: Prints an error message and exits if the list is empty.
 */
char CharLinkedList::first() const 
{
    if (front == nullptr) {
        cerr << "Cannot get the first element of an empty list" << endl;
        exit(EXIT_FAILURE); 
    }
    return front->data;
}

/* last
 *    Purpose: Get the last element in the list.
 * Parameters: none
 *    Returns: The last element in the list, as a char.
 * 
 *       Note: Prints an error message and exits if the list is empty.
 */
char CharLinkedList::last() const 
{
    if (front == nullptr) {
        cerr << "Cannot get the last element of an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    Node *curr = front;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    return curr->data;
}

/* elementAt
 *    Purpose: Get the character at a given position.
 * Parameters: The index to be accessed, as an int. Should be in bounds; in 
 *             other words, should be in the range [0, size() )
 *    Returns: The element at the specified index, as a char
 *
 *       Note: prints an error and exits if given index is out of range.
 */
char CharLinkedList::elementAt(int idx) const
{
    Node *curr = front;
    if (idx < 0 and idx > size() - 1) {
        cerr << "index IDX not in range [0.." << len << ")" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        for (int i = 0; i < idx; i++) {
            if (curr != nullptr) {
                curr = curr->next;
            }
        }
    }
    return curr->data;
}

/* print
 *    Purpose: Prints the list to the terminal (cout)
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::print() const
{
    Node *curr = front;

    cout << "[CharLinkedList of size " << len << " <<";
    while (curr != nullptr) {
            cout << curr->data;
            curr = curr->next;
    }
    cout << ">>]" << endl;
}

/* clear
 *    Purpose: Makes the list empty
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::clear() 
{
    if (size() == 0) {
        return;
    }
    Node *del = front;
    while (del != nullptr) {
        front = front->next;
        delete del;
        del = front;
    }
    len = 0;
}

/* pushAtBack
 *    Purpose: Adds a character to the back of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtBack(char c)
{
    Node *curr = front;
    Node *add = new Node;
    add->data = c;
    
    //if the list is empty, front points to the new node 
    if (isEmpty()) {
        front = add;
        front->prev = nullptr;
        front->next = nullptr;
        len++;  
    }
    else {
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = add;
        add->prev = curr;
        add->next = nullptr;
        len++;
    }
}

/* pushAtFront
 *    Purpose: Adds a character to the front of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtFront(char c)
{
    Node *add = new Node;
    add->data = c;
    add->prev = nullptr;
    add->next = front;
    front = add;
    len++;
}

/* insertAt
 *    Purpose: Adds a character to the list at a given position
 * Parameters: The character to be added to the list and the position at which
 *             it should be added. The position should be in-bounds, that is,
 *             in the range [0, size()]. Providing size() as the index will
 *             insert the character at the back of the list.
 *    Returns: None
 *
 *       Note: prints an error and exits if given index is out of range.
 * 
 *      To-Do: Would be fun to figure out how to do this recursively -- prev
 *             pointer makes it a little more complicated
 */
void CharLinkedList::insertAt(char c, int idx)
{
    if(idx < 0 or idx > len) {
        cerr << "index IDX not in range [0.." << len << "]" << endl;
        exit(EXIT_FAILURE);
    }
    //inserts at front 
    if (idx == 0) {
        pushAtFront(c);
    }
    //inserts at back 
    else if (idx == len) {
        pushAtBack(c);
    }
    //inserts in the middle
    else {
        Node *curr = front;
        Node *add = new Node;
        add->data = c;
        for(int i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }
        add->next = curr->next;
        curr->next = add;
        add->prev = curr;
        len++;
    }   
}

/* popFromFront
 *    Purpose: Removes the first element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromFront()
{
    if (front == nullptr) {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    //if there's only one element, the list is cleared
    if (this->size() == 1) {
        this->clear();
        len = 0;
    }
    else {
        Node *curr = front;
        front = curr->next;
        curr->next->prev = nullptr;
        delete curr;
        len--;
    }
}

/* popFromBack
 *    Purpose: Removes the last element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromBack()
{
    if (front == nullptr) {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    //if there's only one element, the list is cleared
    if (this->size() == 1) {
        this->clear();
        len = 0;
    }
    else {
        Node *curr = front;
        Node *previous = front;
        while (curr->next != nullptr) {
            previous = curr;
            curr = curr->next;
        }
        previous->next = nullptr;
        delete curr;
        len--;
    }
}

/* removeAt
 *    Purpose: Removes the element at a given index
 * Parameters: The position at which to remove an element, which should be the
 *             index of an element currently in the list; in other words,
 *             should be in the interval [0, size)
 *    Returns: None
 */
void CharLinkedList::removeAt(int idx)
{
    if (idx < 0 or idx >= size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")"
             << endl;
        exit(EXIT_FAILURE);
    }
    Node *curr = front;
    Node *previous = front;
    //removes from front 
    if (idx == 0) {
        this->popFromFront();
    }
    //removes from back  
    else if(idx == len - 1){
        this->popFromBack();
    }
    //removes from middle
    else {
        for (int i = 0; i < idx; i++) {
            previous = curr;
            curr = curr->next;
        }
        previous->next = curr->next;
        curr->next->prev = previous;
        delete curr;
        len--;
    }
}

/* replaceAt
 *    Purpose: Replaces the element at the given index with the given value
 * Parameters: A character to put in the list and the index of the
 *             element to replace. The index should be in-bounds, in the
 *             range [0, size() )
 *       Note: Prints an error message and exits if the index is out of bounds
 */
void CharLinkedList::replaceAt(char c, int idx)
{
    if (idx < 0 or idx >= len) {
        cerr << "index IDX not in range [0.." << len << ")" << endl;
        exit(EXIT_FAILURE);
    }
    Node *curr = front;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->data = c;
}

/* concatenate
 *    Purpose: Adds the contents of a CharLinkedList to the back of the current 
 *             one.
 * Parameters: A CharLinkedList whose contents should be pushed to the back of 
 *             the current list. Will not be altered
 *    Returns: None
 */
void CharLinkedList::concatenate(const CharLinkedList &other)
{
    if (other.size() == 0) {
        return;
    }
    bool equal = true;
    if (other.size() == this->size()) {
        for (int i = 0; i < this->size(); i++) {
            if (other.elementAt(i) != this->elementAt(i)) {
                equal = false;
            }
        }
    }
    else {
        equal = false;
    }
    if (equal) {
        CharLinkedList copy(other);
        for (int i = 0; i < copy.size(); i++) {
            this->pushAtBack(copy.elementAt(i));
        }
    }
    else {
        for (int i = 0; i < other.size(); i++) {
            this->pushAtBack(other.elementAt(i));
        }
    }
}
