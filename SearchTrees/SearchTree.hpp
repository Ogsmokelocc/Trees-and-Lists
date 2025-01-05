/*
Each record (i.e. each node in the tree) will need to store the following information: 

Name    Species    Gender    Personality    Hobby    Birthday    Catchphrase    Favorite Song    Style 1    Style 2    Color 1    Color 2    Wallpaper    Flooring    Furniture List    Filename    Unique Entry ID

The tree should be sorted by Name. 

You program should have the following data structures: 

A tree class that has at least the following members:

A root data member that points to the root of the binary tree (or to null if the tree is empty).
A constructor
A sorted insert function sort1() that when given a record, creates a new node object and inserts the node into the correct location in the tree by calling a recursive node function to do the insertion.
A sorted insert function sort2() that when given a record, creates a new node object and inserts the node into the correct location in the tree by creating a node pointer and 'walking' it through the tree until it finds the correct location to insert the new node object. 
A search function search1() that when given a name, searches for that name in the tree and returns a pointer to the correct record, or null if the name is not present - by calling a recursive node search function.  
A search function search2() that when given a name, searches for that name in the tree and returns a pointer to the correct record, or null if the name is not present - by creating a node pointer and 'walking' it through the tree until it finds the correct name or finds that the name is not in the tree.
A record class that stores all of the information in one row of the data file as separate data members.

A node class that has at least the following members:
*/
#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

class Node
{
public:
Node();
Node(string data);
string Get_Data();
Node *Get_Right();
Node *Get_Left();
void Set_Data(string data);
void Set_Left(Node *left);
void Set_Right(Node *right);

private:
    Node *Left;
    Node *Right;
    string Data;
};


class Tree
{
private:


public:
    Node *root;
    Node *current;
    Tree():root(nullptr), current(nullptr){}
    void Insert(string data);
    void Print(Node *node);
    
    
    

//need to put in newnode with parsed file data
// then need to make a print function to print out tree
//also need to add delimiter to file to parse only names and all data will be sorted via names
};

#endif