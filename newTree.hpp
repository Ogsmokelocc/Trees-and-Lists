#include<iostream>
#include<sstream>
#include<string>
#include<list>
#include<queue>

using namespace std;

class Root
{
public:
   string Input;
   Root *Left;
   Root *Right;

   Root(){};
   Root(string input): Input(input), Left(nullptr), Right(nullptr){}


   bool MathOperatorFinder()
   {
        return isdigit(Input[0]) || (Input.size() > 1 and isdigit(Input[1]));

   } 

   double isDouble()
   {
        if(MathOperatorFinder())
        {
            return stod(Input);
        }

        double leftVal = Left->MathOperatorFinder();
        double rightVal = Right->MathOperatorFinder();

        if(Input == "+") return leftVal + rightVal;
        if(Input == "-") return leftVal - rightVal;
        if(Input == "*") return leftVal * rightVal;
        if(Input == "/") return leftVal / rightVal;
   }


   void print()
   {
        if(!MathOperatorFinder()) cout<<"(";
        if(Left) Left->print();
        cout<<Input;
        if(Right) Right->print();
        if(!MathOperatorFinder()) cout <<")";
   }

};

class MathTree
{
public:
    Root *root;
    MathTree():root(nullptr){}

    void MakeTrees(string postfixString)
    {
        stack<Root*> Stack;
        stringstream ss(postfixString);
        string token;

        while(ss >> token)
        {
            Root *newRoot = new Root(token);

            if(newRoot->MathOperatorFinder())
            {
                Stack.push(newRoot);
            } else 
            {
                newRoot->Right = Stack.top(); Stack.pop();
                newRoot->Left = Stack.top(); Stack.pop();
                Stack.push(newRoot);
            }     
        }
        root = Stack.top();
        Stack.pop();
    }

    void PrintInfix()
    {
        if(root)
        {
            root->print();
            cout<<endl;
        }
    }

    double Checker()
    {
        if(root)
        {
            return root->isDouble();
        }
    }
   
      

};