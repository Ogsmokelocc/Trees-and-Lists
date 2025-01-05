/*

For this assignment the goal is to be able to search by either name or catchphrase. This will require two search trees one sorted by name, and one sorted by catchphrase. Every time and insert or delete function is called it will need to be applied to both trees. To accomplish this, create a new class that contains two tree objects (one for names and one for catchphrases).

In the main() function create a menu that allows the user to select:

delete by name
delete by catchphrase
search by name
search by catchphrase
print in-order by name
print in-order by catchphrase
exit
Note that for deletions once the record is deleted from one tree you will need to use the returned record to delete the same record from the other tree. E.g. if the user deletes Knox (from the name tree) the program will also need to delete clucking from the catchphrase tree.

You may use a shorter version of the input file for this assignment - it can make the output easier to read.
*/

// when deleting might have to change the "deleted value to index of zero if we delete by index, if both indexes = 0 then delete the whole node"

#include <iostream>
#include <string>
#include <vector>
#include<string>

using namespace std;
const int k = 2; // dimension of tree (2d tree)
class Node
{
public:
    string point[k];
    Node *Left, *Right;

    Node() : Left(nullptr), Right(nullptr)
    {
        point[0] = "";
        point[1] = "";
    };
    Node(string x, string y) : Left(nullptr), Right(nullptr)
    {
        point[0] = x;
        point[1] = y;
    }; // intialize with custom class
};

class K_Dtree
{
public:
    Node *root;
    K_Dtree() : root(nullptr) {}

    // method to make new node
    Node *newNode(string arr[]);
    /*
    inserts a new node and returns
    the parameter is the depth used to decide the axis
    */
    Node *insertRec(Node *root, string point[], unsigned depth);
    /*
    method to insert a new point with given point in kd
    tree and return a new root it uses the insertrec method above as a form of recursion
    */

    // method to delete whole node,
    Node *deleteNode(Node *node, string point[], unsigned depth);
    // utility function for *deleteNode
    Node *deleteNode(string point[]);
    Node *findMinRec(Node *node, int d, unsigned depth);

    Node *findMin(Node *node, int d);

    

    Node *minNode(Node *x, Node *y, Node *z, int d);


    void copyPoint(string p1[], string p2[]);

    
    void insert(string point[]); // might need Node *node as a parameter

    // utility method to determine if two points are k dimensional
    bool arePointSame(string point1[], string point2[]);

    // searches a point represented by a point in the kd tree
    //  the parameter is the depth used to determine the current axis
    bool searchRec(Node *node, string point[], unsigned depth);

    // searches for a point in the kd tree
    bool search(string point[]); // might need Node *node as a parameter

    // searches for data via index of point in node class
    bool searchByIndex(Node *node, string value, int index, unsigned depth);

    // utility search by index;
    bool searchByIndex(string value, int index);

    // print function that prints values by index in point
    void printByindex(Node *node, int index);
    // utility function to print
    void print(int index);

    void printByName();
    void printByCatchPhrase();
};

Node *K_Dtree::newNode(string arr[])
{
    Node *temp = new Node(arr[0], arr[1]);

    return temp;
}

Node *K_Dtree::insertRec(Node *node, string point[], unsigned depth)
{
    // if the tree is empty
    if (node == nullptr)
    {
        return newNode(point);
    }

    // do the math to find the current dimension of tree
    unsigned currentDim = depth % k;

    /*
    compare the new point with the root on the current dimension and decide the Left or Right subtree
    */

    if (point[currentDim].compare(node->point[currentDim]) < 0)
    {
        node->Left = insertRec(node->Left, point, depth + 1);
    }

    else
    {
        node->Right = insertRec(node->Right, point, depth + 1);
    }

    return node;
}

void K_Dtree::insert(string point[])
{
    root = insertRec(root, point, 0);
}

bool K_Dtree::arePointSame(string point1[], string point2[])
{
    // compare individual values of nodes
    for (int i = 0; i < k; i++)
    {
        if (point1[i] != point2[i])
        {
            return false;
        }
    }
    return true;
}

bool K_Dtree::searchRec(Node *node, string point[], unsigned depth)
{
    // base case
    if (node == nullptr)
    {
        return false;
    }

    if (arePointSame(node->point, point))
    {
        return true;
    }

    // current dimension is computed using the current depth and the total amount of dimensions

    unsigned currentDim = depth % k;

    // compare point with respect to the current dimension
    if (point[currentDim] < node->point[currentDim])
    {
        return searchRec(node->Left, point, depth + 1);
    }
    else
    {
        return searchRec(node->Right, point, depth + 1);
    }
}

bool K_Dtree::search(string point[])
{
    // make sure to pass depth as 0 as a parameter
    return (searchRec(root, point, 0));
}

bool K_Dtree::searchByIndex(Node *node, string value, int index, unsigned depth)
{
    // base case
    if (node == nullptr)
    {
        return false;
    }

    // check if the value of the given index is equal to the actual  value at that index
    if (node->point[index] == value)
    {
        cout << node->point[index];
        return true;
    }

    // comparing value with respect to the current value at the current dimesnion

    if (value < node->point[index])
    {
        return searchByIndex(node->Left, value, index, depth + 1);
    }
    else
    {
        return searchByIndex(node->Right, value, index, depth + 1);
    }
}

bool K_Dtree::searchByIndex(string value, int index)
{
    // pass 0 in as the parameter for depth
    return searchByIndex(root, value, index, 0);
}


Node *K_Dtree::minNode(Node *x, Node *y, Node *z, int d)
{
    Node *A = x;
    if(y != nullptr && y->point[d] < A->point[d])
    {
        A = y;
    }
    if(z != nullptr && z ->point[d] < A->point[d])
    {
        A = z;
    }

    return A;
}



Node *K_Dtree::findMinRec(Node *node, int d, unsigned depth)
{
 //base
 if(node == nullptr)
 {
    return nullptr;
 }

 unsigned currentDim = depth % k;

 if(currentDim == d)
 {
    if(node->Left == nullptr)
    {
        return node;
    }
    return findMinRec(node->Left, d, depth + 1);
 }

 return minNode(node, findMinRec(node->Left, d, depth + 1), findMinRec(node->Right, d, depth + 1), d);
}

Node *K_Dtree::findMin(Node *root, int d)
{
    return findMinRec(root, d, 0);
}

void K_Dtree::copyPoint(string p1[], string p2[])
{
    for(int i = 0; i<k; i++)
    {
        p1[i] = p2[i];
    }
}


void K_Dtree::printByindex(Node *node, int index)
{
    if (node != nullptr)
    {
        printByindex(node->Left, index);
        cout << node->point[index] << " ";
        printByindex(node->Right, index);
    }
}


void K_Dtree::print(int index)
{
    printByindex(root, index);
}


void K_Dtree::printByName() {
    cout << "In-order by Name: ";
    printByindex(root,0);
    cout << endl;
}


void K_Dtree::printByCatchPhrase(){
    cout << "In-order by Catchphrase: ";
    printByindex(root, 1);
    cout << endl;
}





Node *K_Dtree::deleteNode(Node *node, string point[], unsigned depth)
{
    //base case if tree is empty
    if(node == nullptr)
    {
        return nullptr;
    }

    //find dimension
    unsigned currentDim = depth % k;

    //if node is present that we want to delete
    if(arePointSame(node->point,point))
    {
        //if Right branch is present
        if(node->Right != nullptr)
        {
            // find the roots dimension of Right branch
            Node *min = findMin(node->Right, currentDim);

            // copy minumum to roor
            copyPoint(node->point, min->point);

            //recursively delete the minimum
            node->Right = deleteNode(node->Right, min->point, depth +1);
        }
        else if(node->Left != nullptr)
        {
            Node *min = findMin(node->Left, currentDim);
            copyPoint(node->point, min->point);
            node->Right = deleteNode(node->Left, min->point, depth+1);
        }
        //if node is leaf 
        else
        {
            delete node;
            return nullptr;
        }
        return node;
    }
    //if current node doesnt have a point search
    if(point[currentDim] < node->point[currentDim])
    {
        node->Left = deleteNode(node->Left, point, depth + 1);
    }
    else
    {
        node->Right = deleteNode(node->Right, point, depth + 1);
    }
    return node;

}

Node *K_Dtree::deleteNode(string point[])
{
    return deleteNode(root, point, 0);
}




/*
Node *Tree::deleteNode(Node *&node, string name)
{
    if(node == nullptr)
    {
        cout<<"NULL"<<endl;
        return nullptr;

    }

    if(name < node->Data)
    {
        return deleteNode(node->Left, name);
    } else if(name > node->Data)
    {
        return deleteNode(node->Right, name);
    } else {
        Node *TargetNode = node;

        if(node->Left == nullptr && node->Right == nullptr)
        {
            node = nullptr;
        } else if(node->Left == nullptr)
        {
            node = node->Right;
        } else if(node->Right == nullptr)
        {
            node = node->Left;
        } else {
            Node *newParent = node;
            Node *orphanNode = node->Right;
            while(orphanNode->Left != nullptr)
            {
                newParent = orphanNode;
                orphanNode = orphanNode->Left;
            }

            node->Data = orphanNode->Data;

            if(newParent->Left == orphanNode)
            {
                newParent->Left = orphanNode->Right;
            } else {
                newParent->Right = orphanNode->Right;
            }

            TargetNode = orphanNode;
        }
        return TargetNode;
        delete TargetNode;
    }
}

void Tree::deleteStuff(string search)
{
    deleteNode(root, search);
    cout<<"Deleted: "<<search<<endl;
}

*/