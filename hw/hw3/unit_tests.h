/*
 * HW3: BinarySearchTrees
 * cs15
 * unit_tests.h.h
 * Caroline Chin 
 * 11/18/2021
 * Unit testing for BinarySearchTree.cpp
 */

#include <cassert>
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


/* default constructor test 
 *    Purpose: Tests the default constructor and makes sure it creates an
 *    empty BinarySearchTree with height -1
 *    Parameters: none
 *    Returns: Nothing
 */
void default_constructor_test() {
        BinarySearchTree testBinaryTree;
        testBinaryTree.print_tree();
        assert(testBinaryTree.tree_height() == -1);
} 


/* copy constructor test 
 *    Purpose: Tests the copy constructor on binary trees with no nodes,
 *    one node, and more than one node. Makes sure the second tree is being
 *    copied and printed correctly
 *    Parameters: none
 *    Returns: Nothing
 */
void copy_constructor_test() {
       BinarySearchTree testBinaryTree;
       testBinaryTree.insert(34);
       testBinaryTree.insert(45);
       testBinaryTree.insert(6);
       BinarySearchTree testBinaryTree2(testBinaryTree);
       testBinaryTree.print_tree();
       testBinaryTree2.print_tree();

       BinarySearchTree testBinaryTree3;
       BinarySearchTree testBinaryTree4(testBinaryTree3);
       testBinaryTree3.print_tree();
       testBinaryTree4.print_tree();
       
       BinarySearchTree testBinaryTree5;
       testBinaryTree5.insert(47);
       BinarySearchTree testBinaryTree6(testBinaryTree5);
       testBinaryTree5.print_tree();
       testBinaryTree6.print_tree();
}

/* assignment overload test 
 *    Purpose: creates two binary trees and uses the assignment operator to  
 *      make the lhs contain the same elements as the rhs, if the two are equal
 *      after the assignment operator is called the assignment operator works 
 *      tests for trees of multiple sizes
 *    Parameters: none
 *    Returns: Nothing
 */
void assignment_overload_test() {
        BinarySearchTree testBinaryTree;
        BinarySearchTree testBinaryTree2;
        testBinaryTree = testBinaryTree2;
        assert(testBinaryTree2.tree_height() == -1);
        assert(testBinaryTree.tree_height() == -1);
        testBinaryTree2.insert(6);
        testBinaryTree = testBinaryTree2;
        assert(testBinaryTree.tree_height() == 0);
        testBinaryTree.print_tree();
        testBinaryTree2.insert(7);
        testBinaryTree2.insert(0);
        testBinaryTree2.insert(1000);
        testBinaryTree2.insert(999);
        testBinaryTree = testBinaryTree2;
        testBinaryTree.print_tree();
}

/* height test 
 *    Purpose: Tests the height function on binary trees with no nodes,
 *    one node, and more than one node. Checks if the correct height is
 *    being returned
 *    Parameters: none
 *    Returns: Nothing
 */
void height_test() {
        BinarySearchTree testBinaryTree;
        assert(testBinaryTree.tree_height() == -1);
        testBinaryTree.insert(5);
        assert(testBinaryTree.tree_height() == 0);
        testBinaryTree.insert(20);
        testBinaryTree.insert(3);
        testBinaryTree.insert(3);
        assert(testBinaryTree.tree_height() == 1);
        testBinaryTree.print_tree();
        testBinaryTree.insert(1);
        assert(testBinaryTree.tree_height() == 2);
        testBinaryTree.insert(2);
        testBinaryTree.insert(0);
        testBinaryTree.insert(22);
        assert(testBinaryTree.tree_height() == 3);
        testBinaryTree.insert(100);
        testBinaryTree.print_tree();
        assert(testBinaryTree.tree_height() == 3);
        testBinaryTree.insert(101);
        assert(testBinaryTree.tree_height() == 4);
}


/* insert test 
 *    Purpose: Tests the insert function on binary trees with no nodes,
 *    one node, and more than one node. Makes sure nodes are being correctly 
 *    inserted into the tree
 *    Parameters: none
 *    Returns: Nothing
 */
void insert_test() {
        BinarySearchTree testBinaryTree;
        testBinaryTree.insert(9);
        assert(testBinaryTree.tree_height() == 0);
        testBinaryTree.insert(6);
        testBinaryTree.insert(11);
        testBinaryTree.insert(8);
        testBinaryTree.insert(10);
        testBinaryTree.insert(9);
        testBinaryTree.insert(16);
        testBinaryTree.insert(5);
        testBinaryTree.insert(1);
        testBinaryTree.insert(2);
        testBinaryTree.insert(12);
        testBinaryTree.print_tree();
}

/* find_min test 
 *    Purpose: Tests the find min function on binary trees with no nodes,
 *    one node, and more than one node. Checks if find_min is returning the 
 *    node with the smallest value in the tree
 *    Parameters: none
 *    Returns: Nothing
 */
void min_test() {
        BinarySearchTree testBinaryTree;
        testBinaryTree.find_min();
        testBinaryTree.insert(5);
        assert(testBinaryTree.find_min() == 5);
        testBinaryTree.insert(20);
        testBinaryTree.insert(3);
        testBinaryTree.insert(3);
        testBinaryTree.insert(1);
        assert(testBinaryTree.find_min() == 1);
        testBinaryTree.insert(2);
        testBinaryTree.insert(0);
        testBinaryTree.insert(22);
        testBinaryTree.print_tree();
        assert(testBinaryTree.find_min() == 0);
}

/* find_max test 
 *    Purpose: Tests the find max function on binary trees with no nodes,
 *    one node, and more than one node. Checks if find_min is returning the 
 *    node with the greatest value in the tree
 *    Parameters: none
 *    Returns: Nothing
 */
void max_test() {
        BinarySearchTree testBinaryTree;
        testBinaryTree.find_max();
        testBinaryTree.insert(5);
        assert(testBinaryTree.find_max() == 5);
        testBinaryTree.insert(20);
        testBinaryTree.insert(3);
        testBinaryTree.insert(3);
        testBinaryTree.insert(1);
        assert(testBinaryTree.find_max() == 20);
        testBinaryTree.insert(2);
        testBinaryTree.insert(0);
        testBinaryTree.insert(22);
        testBinaryTree.print_tree();
        assert(testBinaryTree.find_max() == 22);
}

/* contain test 
 *    Purpose: Tests the contains function on binary trees with no nodes,
 *    one node, and more than one node. Also tests for nodes that do not 
 *    exist in the tree, which should return false. Checks if contain is 
 *    returning the correct boolean for elements in and out of the tree
 *    Parameters: none
 *    Returns: Nothing
 */
void contain_test() {
        BinarySearchTree testBinaryTree;
        //causes expected error
        //assert(testBinaryTree.contains(0));
        testBinaryTree.insert(5);
        assert(testBinaryTree.contains(5));
        //cause expected errors
        //assert(testBinaryTree.contains(20));
        //assert(testBinaryTree.contains(0));
        testBinaryTree.insert(20);
        testBinaryTree.insert(3);
        testBinaryTree.insert(3);
        testBinaryTree.insert(1);
        testBinaryTree.insert(2);
        testBinaryTree.insert(0);
        testBinaryTree.insert(22);
        assert(testBinaryTree.contains(1));
        assert(testBinaryTree.contains(3));
        assert(testBinaryTree.contains(20));
        //cause expected errors
        //assert(testBinaryTree.contains(9));
        //assert(testBinaryTree.contains(73));
        //assert(testBinaryTree.contains(4));
}

/* count test 
 *    Purpose: Tests the node_count function on binary trees with no nodes,
 *    one node, and more than one node. Checks if node_count is returning 
 *    the correct number of nodes in the tree. Also tests with duplicates in 
 *    the tree
 *    Parameters: none
 *    Returns: Nothing
 */
void count_test() {
        BinarySearchTree testBinaryTree;
        assert(testBinaryTree.node_count() == 0);
        testBinaryTree.insert(5);
        assert(testBinaryTree.node_count() == 1);
        testBinaryTree.insert(20);
        testBinaryTree.insert(3);
        testBinaryTree.insert(3);
        assert(testBinaryTree.node_count() == 3);
        testBinaryTree.insert(1);
        testBinaryTree.insert(2);
        testBinaryTree.insert(0);
        testBinaryTree.insert(22);
        assert(testBinaryTree.node_count() == 7);
}

/* total test 
 *    Purpose: Tests the count_total function on binary trees with no nodes,
 *    one node, and more than one node. Checks if count_total is returning 
 *    the correct sum of the nodes in the tree. Also tests with duplicates in 
 *    the tree
 *    Parameters: none
 *    Returns: Nothing
 */
void total_test() {
        BinarySearchTree testBinaryTree;
        assert(testBinaryTree.count_total() == 0);
        testBinaryTree.insert(5);
        assert(testBinaryTree.count_total() == 5);
        testBinaryTree.insert(20);
        testBinaryTree.insert(3);
        testBinaryTree.insert(3);
        testBinaryTree.insert(1);
        assert(testBinaryTree.count_total() == 32);
        testBinaryTree.insert(2);
        testBinaryTree.insert(0);
        testBinaryTree.insert(22);
        assert(testBinaryTree.count_total() == 56);
        testBinaryTree.insert(22);
        assert(testBinaryTree.count_total() == 78);
}

/* remove1 test 
 *    Purpose: Tests the remove function on binary trees with no nodes,
 *    one node, and on nodes without children. Uses both assert statements
 *    and prints the initial and final tree.
 *    Parameters: none
 *    Returns: Nothing
 */
void remove_test1() {
        //causes expected error
        // BinarySearchTree testBinaryTree;
        // assert(testBinaryTree.remove(9));

        //removing nodes with no children
        //also tests removing a single node tree
        BinarySearchTree testBinaryTree2;
        testBinaryTree2.insert(15);
        testBinaryTree2.insert(30);
        testBinaryTree2.insert(2);
        testBinaryTree2.insert(16);
        testBinaryTree2.insert(32);
        testBinaryTree2.insert(6);
        testBinaryTree2.print_tree();
        assert(testBinaryTree2.remove(32));
        assert(testBinaryTree2.remove(16));
        assert(testBinaryTree2.remove(30));
        assert(testBinaryTree2.remove(6));
        assert(testBinaryTree2.remove(2));
        assert(testBinaryTree2.remove(15));
        testBinaryTree2.print_tree();
        //causes expected error
        // assert(testBinaryTree2.remove(30));
}

/* remove2 test 
 *    Purpose: Tests the remove function on nodes with two children.
 *    Uses both assert statements and prints the initial and final tree
 *    to check if the node was being removed correctly.
 *    Parameters: none
 *    Returns: Nothing
 */
void remove_test2() {
        //removing node with two children
        BinarySearchTree testBinaryTree3;
        testBinaryTree3.insert(30);
        testBinaryTree3.insert(40);
        testBinaryTree3.insert(50);
        testBinaryTree3.insert(36);
        testBinaryTree3.print_tree();
        assert(testBinaryTree3.remove(40));
        testBinaryTree3.print_tree();
        testBinaryTree3.insert(20);
        testBinaryTree3.insert(25);
        testBinaryTree3.insert(22);
        testBinaryTree3.insert(28);
        testBinaryTree3.insert(29);
        testBinaryTree3.print_tree();
        assert(testBinaryTree3.remove(25));
        assert(testBinaryTree3.remove(28));
        testBinaryTree3.print_tree();
}

/* remove3 test 
 *    Purpose: Tests the remove function on nodes with only a right child.
 *    Uses both assert statements and prints the initial and final tree
 *    to check if the node was being removed correctly.
 *    Parameters: none
 *    Returns: Nothing
 */
void remove_test3() {
        //removing node with only a right child
        BinarySearchTree testBinaryTree;
        testBinaryTree.insert(5);
        testBinaryTree.insert(10);
        testBinaryTree.insert(20);
        testBinaryTree.insert(31);
        testBinaryTree.insert(45);
        testBinaryTree.insert(88);
        testBinaryTree.print_tree();
        assert(testBinaryTree.remove(5));
        assert(testBinaryTree.remove(31));
        assert(testBinaryTree.remove(88));
        assert(testBinaryTree.remove(45));
        assert(testBinaryTree.remove(10));
        testBinaryTree.print_tree();
        assert(testBinaryTree.remove(20));
}

/* remove4 test 
 *    Purpose: Tests the remove function on nodes with only a left child.
 *    Uses both assert statements and prints the initial and final tree
 *    to check if the node was being removed correctly.
 *    Parameters: none
 *    Returns: Nothing
 */
void remove_test4() {
        //removing node with only a left child
        BinarySearchTree testBinaryTree;
        testBinaryTree.insert(45);
        testBinaryTree.insert(43);
        testBinaryTree.insert(40);
        testBinaryTree.insert(37);
        testBinaryTree.insert(30);
        testBinaryTree.insert(0);
        testBinaryTree.print_tree();
        assert(testBinaryTree.remove(0));
        assert(testBinaryTree.remove(40));
        assert(testBinaryTree.remove(45));
        assert(testBinaryTree.remove(37));
        assert(testBinaryTree.remove(43));
        testBinaryTree.print_tree();
}

/* remove3 test 
 *    Purpose: Tests the remove function on nodes with duplicates and
 *    nodes that do no exist in the tree.
 *    Uses both assert statements and prints the initial and final tree
 *    to check if the node was being removed correctly.
 *    Parameters: none
 *    Returns: Nothing
 */
void remove_test5() {
        //duplicates and nonextistent nodes
        BinarySearchTree testBinaryTree;
        testBinaryTree.insert(24);
        testBinaryTree.insert(24);
        testBinaryTree.insert(24);
        testBinaryTree.insert(33);
        testBinaryTree.insert(26);
        testBinaryTree.insert(27);
        testBinaryTree.insert(26);
        testBinaryTree.insert(20);
        testBinaryTree.insert(23);
        testBinaryTree.insert(23);
        testBinaryTree.insert(21);
        testBinaryTree.insert(21);
        testBinaryTree.print_tree();
        //cause expected errors
        //assert(testBinaryTree.remove(25));
        //assert(testBinaryTree.remove(34));
        //assert(testBinaryTree.remove(18));

        assert(testBinaryTree.remove(24));
        assert(testBinaryTree.remove(24));
        assert(testBinaryTree.remove(24));
        assert(testBinaryTree.remove(26));
        assert(testBinaryTree.remove(23));
        assert(testBinaryTree.remove(23));
        testBinaryTree.print_tree();
}

/* remove6 test 
 *    Purpose: A mix of remove tests on one tree. Makes sure 
 *    nodes were removed correctly and prints the initial and
 *    final tree.
 *    Parameters: none
 *    Returns: Nothing
 */
void remove_test6() {
        //mixed test
        BinarySearchTree testBinaryTree4;
        testBinaryTree4.insert(20);
        testBinaryTree4.insert(20);
        testBinaryTree4.insert(15);
        testBinaryTree4.insert(35);
        testBinaryTree4.insert(40);
        testBinaryTree4.insert(50);
        testBinaryTree4.insert(30);
        testBinaryTree4.insert(33);
        testBinaryTree4.insert(24);
        testBinaryTree4.insert(10);
        testBinaryTree4.insert(16);
        testBinaryTree4.insert(60);
        testBinaryTree4.insert(70);
        testBinaryTree4.insert(90);
        testBinaryTree4.print_tree();
        assert(testBinaryTree4.remove(20));
        assert(testBinaryTree4.remove(60));
        assert(testBinaryTree4.remove(70));
        assert(testBinaryTree4.remove(90));
        assert(testBinaryTree4.remove(35));
        assert(testBinaryTree4.remove(15));
        assert(testBinaryTree4.remove(16));
        assert(testBinaryTree4.remove(20));
        assert(testBinaryTree4.remove(30));
        assert(testBinaryTree4.remove(40));
        testBinaryTree4.print_tree();
}