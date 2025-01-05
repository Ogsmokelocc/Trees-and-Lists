#include<iostream>
#include"mathTree.hpp"

using namespace std;

int main()
{
   string expr1 = "3.5 5 +"; // idk if its suppose to be like 3.5 + 5 in the homework it says from postfix 
   string  expr2 = "2.5 3 + 4.1 *";
   string expr3 = "7.5 3.2 2 1 + * -";

   Tree<string> tree1, tree2, tree3;
   tree1.PostFixTree(expr1);
   tree2.PostFixTree(expr2);
   tree3.PostFixTree(expr3);

    tree1.infixPrint();
    cout<<" = " << tree1.Eval() << endl;
}