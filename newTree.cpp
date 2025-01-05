#include<iostream>
#include<sstream>
#include<string>
#include<list>
#include<queue>
#include"newTree.hpp"

using namespace std;

int main()
{


string expr1 = "3.5 5 +";
string expr2 = "2.5 3 + 4.1 *";
string expr3 = "7.5 3.2 2 1 + * -";

MathTree tree1 ,tree2, tree3;
tree1.MakeTrees(expr1);
tree1.PrintInfix();
cout<< " = " << tree1.Checker() <<endl;

tree2.MakeTrees(expr2);
tree2.PrintInfix();
cout<<" = " <<tree2.Checker() <<endl;

tree3.MakeTrees(expr3);
tree3.PrintInfix();
cout<<" = " <<tree3.Checker() <<endl;

return 0;
}





