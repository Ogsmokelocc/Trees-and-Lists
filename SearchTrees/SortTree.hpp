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

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

class Node
{
public:
    string Data;
    Node *Left;
    Node *Right;
    Node(string data)
    {
        Data = data;
        Left = nullptr;
        Right = nullptr;
    }
};

class Tree
{
public:
    Node *root;
    Tree() : root(nullptr) {};
    void PrintInorder(Node *node);
    void sortInsert(string newString); // sorted insert
    void SortInsert2(Node *node,string newString);
    void insert(string);
    void Print();
    void printNames();
    void PrintLine();
    void LoadTreeNames();
    void search(Node *node, string SearchInput);
    void search2(string Search);
    void deleteNode(Node *&,string search);
    vector<string> ParseFile(const string &fileName, char delimiter);
    vector<string> ParseWHoleLine(const string &fileName, char delimter);
};

void Tree::sortInsert(string newString) // insert sort
{
    Node *temp = new Node(newString);

    if (root == nullptr)
    {
        root = temp;
        return;
    }

    Node *parent = nullptr, *current = root;
    while (current != nullptr)
    {
        // strcompare < 0 means string1 is less than string 2
        //  >0 means string 1 is greater than string 2
        //  ==0 means both strings are equal

        /*
        find the node that is going to have a new node as
        its child
        */
        parent = current;
        if (current->Data.compare(newString) > 0)
        {
            current = current->Left;
        }
        else if (current->Data.compare(newString) < 0)
        {
            current = current->Right;
        }
        else
        {
            return;
        }
    }
    /*
    if the new string is smaller
    than we make it left child, else its greater than root
    */
    if (parent->Data.compare(newString) > 0)
    {
        parent->Left = temp;
    }
    else
    {
        parent->Right = temp;
    }
    return;
}

void Tree::PrintInorder(Node *node)
{
    if (node != nullptr)
    {
        PrintInorder(node->Left);
        cout << node->Data << endl;
        PrintInorder(node->Right);
    }
}

void Tree::SortInsert2( Node *node,string newString)
{
    if(node == nullptr)
    {
        node = new Node(newString);
        return;
    }

    if(root->Data < node->Data)
    {
        SortInsert2(node->Left, newString);
    } else if(root->Data > node->Data)
    {
        SortInsert2(node->Right, newString);
    }

}

void Tree::insert(string Newstring)
{
    SortInsert2(root,Newstring);
}

void Tree::Print()
{
    PrintInorder(root);
}

vector<string> Tree::ParseFile(const string &fileName, char delimiter)
{
    fstream file(fileName);
    vector<string> FileData;
    string token;

    if (file.is_open())
    {
        while (getline(file, token))
        {
            stringstream ss(token);
            string name;
            if (getline(ss, name, ','))
            {
                FileData.push_back(name);
            }
        }
    }
    return FileData;
}

vector<string> Tree::ParseWHoleLine(const string &fileName, char delimter)
{
    fstream file(fileName);
    vector<string> FileData;
    string token;

    if (file.is_open())
    {
        while (getline(file, token, delimter))
        {
            FileData.push_back(token);
        }
    }

    return FileData;
}

void Tree::printNames()
{
    vector<string> Name;

    Name = ParseFile("villagers.csv", '$');
    for (size_t i = 1; i < Name.size(); i++)
    {
        cout << Name[i] << endl;
    }
}

void Tree::PrintLine()
{
    vector<string> Line;
    Line = ParseWHoleLine("villagers.csv", '$');
    for (size_t i = 1; i < Line.size(); i++)
    {
        cout << Line[i] << endl;
    }
}

void Tree::LoadTreeNames() // inserting into nodes(records) from vector
{
    vector<string> Names;
    Names = ParseFile("villagers.csv", '$');

    for (size_t i = 1; i < Names.size(); i++)
    {
        sortInsert(Names[i]);
    }
}

void Tree::search(Node *node, string SearchInput)
{
    vector<string> Lines;
    vector<string> Names;
    Names = ParseFile("villagers.csv", '$');
    Lines = ParseWHoleLine("villagers.csv", '$');
    if (node != nullptr)
    {
        if (SearchInput == node->Data)
        {
            for (size_t i = 0; i < Lines.size(); i++)
            {
                if (Names.at(i) == SearchInput)
                {
                    cout << "Name is: " << Names.at(i) << " ";
                    cout << "\n"
                    << "Record Data: " << Lines.at(i) << " ";
                    return;
                }
                else if (SearchInput != node->Data)
                {
                    cout << "Does not exist" << endl;
                }
            }
        }
        search(node->Left, SearchInput);
        search(node->Right, SearchInput);
    }

    return;
}

void Tree::search2(string Search)
{
    search(root, Search);
}


void Tree::deleteNode(Node *&,string Search)
{
    
}
/*last thing i did was add all the names to the tree, we need to add some functionality to the tree class
possibly add just return the vector index assoiciated with the name.
*/