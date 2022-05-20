/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

/* Default Constructor
 *    Purpose: Creates an empty Binary Search Tree
 *    Parameters: none
 *    Returns: Nothing
 */
BinarySearchTree::BinarySearchTree()
{
        root = nullptr;
}

/* Destructor
 *    Purpose: Calls post_order_delete to delete nodes from the tree
 *    and clear up memory
 *    Parameters: none
 *    Returns: Nothing
 */
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}

/* post_order_delete
 *    Purpose: Helper function of the destructor and recursively deletes
 *    nodes in post order
 *    Parameters: Node from where the tree is being deleted
 *    Returns: Nothing
 */
void BinarySearchTree::post_order_delete(Node *node)
{
        if (node == nullptr) {
                return;
        }
        post_order_delete(node->left);
        post_order_delete(node->right);
        
        node->left = nullptr;
        node->right = nullptr;
        node->data = -1;
        node->count = -1;
        delete node;
}

/* Copy Constructor
 *    Purpose: Creates a copy of a binary search tree and calls helper
 *    function to copy nodes recursively
 *    Parameters: address of binary search tree
 *    Returns: Nothing
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

/* Assignment Operator
 *    Purpose: Clears the lhs and sets the lhs equal to the rhs
 *    by copying the tree on the rhs. Calls helper functions
 *    post order delete and pre order copy
 *    Parameters: address of binary search tree
 *    Returns: new lhs
 */
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        if (this != &source) {
                post_order_delete(root); // clear the current tree
                // add each element from the other tree into this one
                root = pre_order_copy(source.root);
        }
        return *this;
}

/* Pre Order Copy
 *    Purpose: Creates a copy of a binary search tree through recursion
 *    and in pre order.
 *    Parameters: Node currently being copied, recurses through the rest of the tree
 *    Returns: Copied node
 */
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        if (node == nullptr) {
                return nullptr;
        }
        else {
                Node *copy = new Node;
                copy->data = node->data;
                copy->count = node->count;
                copy->left = pre_order_copy(node->left);
                copy->right = pre_order_copy(node->right);
                return copy;
        }
}

/* find_min(public)
 *    Purpose: Checks if the tree is empty and return the smallest 
 *    int if empty calls private helper function find_min to recurse 
 *    through subtree
 *    Parameters: none
 *    Returns: Int value of the smallest node
 */
int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}


 /* find_min(private)
 *    Purpose: Given a node, finds the smallest value within that node
 *    and it's subtree
 *    Parameters: Node to begin recursively searching for the smallest value
 *    Returns: Node with the smallest value
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        if (node->left == nullptr) {
                return node;
        }
        else {
                return find_min(node->left);
        }   
}

/* find_max(public)
 *    Purpose: Checks if the tree is empty and return the largest 
 *    int if empty calls private helper function find_min to 
 *    recurse through subtree
 *    Parameters: none
 *    Returns: Int value of the largest node
 */
int BinarySearchTree::find_max() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_max(root)->data;
}

 /* find_max(private)
 *    Purpose: Given a node, finds the largest value within that node
 *    and it's subtree
 *    Parameters: Node to begin recursively searching for the largest value
 *    Returns: Node with the largest value
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        if (node->right == nullptr) {
                return node;
        }
        else {
                return find_max(node->right);
        }  
}

 /* contains(public)
 *    Purpose: Given a value, calls the private helper contains function
 *    with the root and given value
 *    Parameters: Value of node to be found
 *    Returns: Bool of whether or not the node was found successfully
 */
bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

 /* contains(private)
 *    Purpose: Given a node and a value, begins searching at given node for
 *    the node with the given value
 *    Parameters: Node to begin recursively searching for and value of node
 *    to be found
 *    Returns: Bool of whether or not the node was found
 */
bool BinarySearchTree::contains(Node *node, int value) const
{
        if (node == nullptr) {
                return false;
        }
        else if (node->data == value) {
                return true;
        }
        else if (value < node->data) {
                if (node->left == nullptr) {
                        return false;
                }
                return contains(node->left, value);
        }
        else if (value > node->data) {
                if (node->right == nullptr) {
                        return false;
                }
                return contains(node->right, value);
        }
        return false;
}
 
 /* insert(public)
 *    Purpose: Given a value, calls the insert helper function with the root
 *    of the tree, its parent, and value of node to be inserted
 *    Parameters: Value of node to be inserted
 *    Returns: None
 */
void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}

 /* insert(private)
 *    Purpose: Given a node, parent, and value, recurses through the tree to
 *    find the correct position for the node to be inserted, and then inserts
 *    the node at the correct position
 *    Parameters: Node to begin recursively searching from, its parent, value of
 *    node to be inserted
 *    Returns: None
 */
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        if (root == nullptr) {
                root = new_node(value, nullptr, nullptr);
        }
        else if (node->data == value) 
                node->count++;
        else if (value < node->data) {
                if (node->left == nullptr) 
                        node->left = new_node(value, nullptr, nullptr);
                else
                        insert(node->left, node, value);
        }
        else if (value > node->data) {
                if (node->right == nullptr) {
                        node->right = new_node(value, nullptr, nullptr);
                }
                else
                        insert(node->right, node, value);
        }
}

 /* remove(public)
 *    Purpose: Given a value, calls the private helper remove function with
 *    the root, its parent, and given value to remove
 *    Parameters: Value of node to be removed
 *    Returns: Bool of whether or not the node was removed
 */
bool BinarySearchTree::remove(int value)
{
        return remove(root, nullptr, value);
}

 /* remove(private)
 *    Purpose: Given a node, parent, and value, recursively searches for node
 *    of given value starting with the given node. If values match, node is removed
 *    Parameters: Node to begin recursively searching from, its parent, value of 
 *    node to be removed
 *    Returns: Bool of whether or not the node was removed
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        if (node == nullptr) {
                return false;
        }
        else if (node->data == value) {
                if (node->count > 1) {
                        node->count--;
                        return true;
                }
                else if (node->left == nullptr and node->right == nullptr) {
                        if (parent != nullptr and value < parent->data) {
                                parent->left = nullptr;
                                delete node;
                        }
                        else if (parent != nullptr and value >= parent->data) {
                                parent->right = nullptr;
                                delete node;
                        }
                        return true;
                }
                else if (node->right != nullptr and node->left != nullptr) {
                        node->data = find_min(node->right)->data;
                        node->count = find_min(node->right)->count;
                        if (find_min(node->right)->count > 1) {
                                for (int i = 0; i <= node->right->count; i++) {
                                        remove(node->right, node, find_min(node->right)->data);
                                }
                        }
                        else {
                                remove(node->right, node, find_min(node->right)->data);
                        }
                        
                        return true;
                }
                else if (node->right != nullptr and node->left == nullptr) {
                        node->data = node->right->data;
                        node->count = node->right->count;
                        remove(node->right, node, node->right->data);
                        return true;
                }
                else if (node->left != nullptr and node->right == nullptr) {
                        if (parent == nullptr) {
                                root = node->left;
                        }
                        else if (parent->data < node->left->data) {
                                parent->right = node->left;
                        }
                        else {
                                parent->left = node->left;
                        }
                        delete node;
                        return true;
                }
        }
        else if (value < node->data) {
                return remove(node->left, node, value);
        }
        else if (value > node->data) {
                return remove(node->right, node, value);
        }
}

/* tree_height(public)
 *    Purpose: Calls private helper tree_height function with the root
 *    of the tree it is being called on 
 *    Parameters: None
 *    Returns: Int value of height of tree
 */
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

/* tree_height(private)
 *    Purpose: Recursively moves down the left and right subtree
 *    and returns the greater height
 *    Parameters: Node to begin counting
 *    Returns: Int of tree height
 */
int BinarySearchTree::tree_height(Node *node) const
{
        if (node == nullptr) {
                return -1;
        }

        else if (node->left == nullptr and node->right == nullptr) {
                return 0;
        }

        else {
                int left_height = tree_height(node->left);
                int right_height = tree_height(node->right);
     
                if (left_height > right_height) {
                        return(left_height + 1);
                }
                else {
                        return(right_height + 1);
                }
        }
}

/* node_count(public)
 *    Purpose: Calls private helper function with the root of the tree
 *    Parameters: None
 *    Returns: number of nodes in tree
 */
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

/* node_count(private)
 *    Purpose: Given a node, recursively counts how many nodes are in that
 *    subtree including itself
 *    Parameters: Node to begin counting
 *    Returns: number of nodes in subtree
 */
int BinarySearchTree::node_count(Node *node) const
{
        int count = 1;
        if (node == nullptr) {
                return 0;
        }
        else {
                count += node_count(node->left) + node_count(node->right);
                return count;
        }
}

/* count_total(public)
 *    Purpose: Calls private helper count_total function
 *    with the root of the tree
 *    Parameters: None
 *    Returns: sum of nodes in tree with duplicates
 */
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

/* count_total(private)
 *    Purpose: recursively reaches every node and adds the value to 
 *    the sum
 *    Parameters: Node to start adding from
 *    Returns: sum of nodes in tree with duplicates
 */
int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr) {
                return 0;
        }
        else {
                return (node->data * node->count) + count_total(node->left) + count_total(node->right);
        }
}

BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}

/* new_node
 *    Purpose: creates a new node with given paramenters
 *    Parameters: data value, pointer to left child, pointer to 
 *    right child
 *    Returns: new node created
 */
BinarySearchTree::Node *BinarySearchTree::new_node(int d, 
                                                Node *l, Node *r) const
{
        Node *n = new Node;
        n->data = d;
        n->left = l;
        n->right = r;
        n->count = 1;
        return n;
}
