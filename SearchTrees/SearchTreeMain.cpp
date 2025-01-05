#include <iostream>
#include "SortTree.hpp"

using namespace std;

int main()
{
    Tree tree;
    tree.LoadTreeNames();
    tree.Print();
    cout<<"\n"<<endl;
    tree.search2("Vic");
    cout<<"\n"<<endl;
    tree.search2("Stinky");
    cout<<"\n"<<endl;
    tree.search2("Lily");
    cout<<"\n"<<endl;
    tree.search2("Biskit");
    cout<<"\n\n"<<endl;
    tree.PrintLine();
    return 0;
}