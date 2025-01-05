#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
#include"SearchTree.hpp"

using namespace std;


Node::Node(){};
Node::Node(string data): Data(data), Left(nullptr), Right(nullptr){};
Node *Node::Get_Left()
{
    return Left;
}

Node *Node::Get_Right()
{
    return Right;
}

string Node::Get_Data()
{
    return Data;
}

void Node::Set_Data(string data)
{
    Data = data;
}

void Node::Set_Left(Node *left)
{
    Left = left;
}

void Node::Set_Right(Node *right)
{
    Right = right;
}

//--------------Tree member defintions 

void Tree::Insert(string data)
{
    Node *newRoot = new Node(data);
    if(root == nullptr)
    {
        root = newRoot;
        return;
    }

    queue<Node*>TreeList;
    TreeList.push(root);

    while(!TreeList.empty())
    {
        Node *current = TreeList.front();
        TreeList.pop();

        if(current->Get_Left() == nullptr)
        {
            current->Set_Left(newRoot);
            return;
        } else
            {
                TreeList.push(current->Get_Left());
            }

        if(current->Get_Right() == nullptr)
        {
            current->Set_Right(newRoot);
            return;
        } else{
            TreeList.push(current->Get_Right());
        }
    }
}


void Tree::Print(Node *node)
{
    if(root != nullptr)
    {
        Print(root->Get_Left());
        cout<<root->Get_Data();
        Print(root->Get_Right());
    }
}

