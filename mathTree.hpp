#include<iostream>
#include<sstream>
#include<unordered_map>
#include<map>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
using namespace std;

//postFix___ ABC * +
//infix____ A+(B+C)

template<typename T>
class Root
{
public:
    T Data;
    string input;
    Root<T> *Left;
    Root<T> *Right;

    bool OperatorFinder()
    {
        return isdigit(input[0]) || (input.size() > 1 and isdigit(input[1]));
    }

    double isDouble()
    {
        if(OperatorFinder())
        {
            return stod(input);
        }

        double leftVal = Left->OperatorFinder();
        double rightVal = Right->OperatorFinder();

        if(input == "+") return leftVal + rightVal;
        if(input == "-") return leftVal - rightVal;
        if(input == "*") return leftVal * rightVal;
        if(input == "/") return leftVal / rightVal;

       // if((input != "+")  or (input != "-") or (input != "*") or (input != "/")); return error or something 
    }

    void print()
    {
        if(!OperatorFinder()) cout<<"(";
        if(Left) Left->print();
        cout << input;
        if(Right) Right->print();
        if(!OperatorFinder()) cout <<")";
    }


    Root(){};
    Root(T data): Data(data), Left(nullptr), Right(nullptr){};
};


//----------------------
//void build from postfix
template<typename T>
class Tree
{
private:
    
    /*
    print functions needed
    */
   void infix(Root<T> *root)
   {
        if(root != nullptr)
        {
            infix(root->Left);
            cout<<root->Data<<" ";
            infix(root->Right);
        }
   }

    void postfix(Root<T> *root)
    {
        if(root != nullptr)
        {
            postfix(root->Left);
            postfix(root->Right);
            cout<<root->Data<<" "; 
        }
    }

    void prefix(Root<T> *root)
{
    if(root != nullptr)
    {
        cout << root->Data<<" ";
        prefix(root->Left);
        prefix(root->Right);
    }
}




public:

    Tree():root(nullptr){}
    Root<T> *root;


    void PostFixTree(string input)
    {
        stack<Root<T>*>Stack;
        stringstream ss(input);
        string token;

        while (ss>>token)
        {
            Root<T> *newRoot = new Root<T>(token);

           if(newRoot->OperatorFinder())
           {
            Stack.push(newRoot);
           } else
           {
            newRoot->Right = Stack.top();
            Stack.pop();
            newRoot->Left = Stack.top();
            Stack.pop();
            Stack.push(newRoot); 
           }
        }
        root = Stack.top();
        Stack.pop();
    }

    double Eval()
    {
        if(root)
        {
            return root->isDouble();
        }
    }
    void insertData(T new_Data)
    {
        Root<T> *newRoot = new Root<T>(new_Data);
        if(root == nullptr)
        {
            root = newRoot;
            return;
        }
        queue<Root<T>*>Que;
        Que.push(root);

        while (!Que.empty())
        {
            Root<T> *current = Que.front();
            Que.pop();

            if(current->Left == nullptr)
            {
                current->Left = newRoot;
                return;
            } else
            {
                Que.push(current->Left);
            }

            if(current->Right == nullptr)
            {
                current->Right = newRoot;
                return;
            } else
            {
                Que.push(current->Right);
            }
        }

    }

    void infixPrint()
    {
        infix(root);
        cout<<endl;
    }

    void postfixPrint()
    {
        postfix(root);
    }


    void prefixPrint()
    {
        prefix(root);
    }

    /*
    print function getters and setters needed
    */
};
