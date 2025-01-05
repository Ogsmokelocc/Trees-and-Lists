#include <iostream>
#include <string>
#include "Btree.h"

using namespace std;
int main()
{
    BinaryTree nameTree, catchphraseTree;
    string filename = "/Users/xavierdahlstet/PuterScience/fuckThis/Binary_Trees/Search_Tree/New_Search_Tree/villagers.csv"; // idk reg path was nor working 
    
    readVillagersFromFile(filename, nameTree, catchphraseTree);

    menu(nameTree, catchphraseTree);

    return 0;
}
