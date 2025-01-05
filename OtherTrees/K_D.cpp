#include <iostream>
#include "KD.hpp"

using namespace std;

int main()
{
 K_Dtree tree;

    // Replacing points with names and catchphrases
    string points[][2] = {
        {"Alice", "Keep smiling!"},
        {"Bob", "Stay positive!"},
        {"Charlie", "Embrace the challenge!"},
        {"Dave", "Make it happen!"},
        {"Eve", "Believe in yourself!"},
        {"Frank", "Keep pushing forward!"},
        {"Grace", "Dream big!"},
        {"Hank", "Stay humble!"}
    };
    int n = sizeof(points) / sizeof(points[0]);

    // Insert names into the tree
    for (int i = 0; i < n; i++)
    {
        tree.insert(points[i]);
    }

    string searchPoint1[] = {"Grace", "Dream big!"};
    string searchPoint2[] = {"Ivy", "Reach for the stars!"};
    string searchPoint3[] = {"Bob", "Stay positive!"};
    string searchPoint4[] = {"Charlie", "Embrace the challenge!"};
    string searchPoint5[] = {"Dave", "Make it happen!"};
    string searchPoint6[] = {"Eve", "Believe in yourself!"};
    string searchPoint7[] = {"Frank", "Keep pushing forward!"};
    string searchPoint8[] = {"Alice", "Keep smiling!"};
    string searchPoint9[] = {"Hank", "Stay humble!"};

    cout << "Searching for {Grace, 'Dream big!'}: " << (tree.search(searchPoint1) ? "Found" : "Not Found") << endl;
    cout << "Searching for {Ivy, 'Reach for the stars!'}: " << (tree.search(searchPoint2) ? "Found" : "Not Found") << endl;
    cout << "Searching for {Bob, 'Stay positive!'}: " << (tree.search(searchPoint3) ? "Found" : "Not Found") << endl;
    cout << "Searching for {Charlie, 'Embrace the challenge!'}: " << (tree.search(searchPoint4) ? "Found" : "Not Found") << endl;
    cout << "Searching for {Dave, 'Make it happen!'}: " << (tree.search(searchPoint5) ? "Found" : "Not Found") << endl;
    cout << "Searching for {Eve, 'Believe in yourself!'}: " << (tree.search(searchPoint6) ? "Found" : "Not Found") << endl;
    cout << "Searching for {Frank, 'Keep pushing forward!'}: " << (tree.search(searchPoint7) ? "Found" : "Not Found") << endl;
    cout << "Searching for {Alice, 'Keep smiling!'}: " << (tree.search(searchPoint8) ? "Found" : "Not Found") << endl;
    cout << "Searching for {Hank, 'Stay humble!'}: " << (tree.search(searchPoint9) ? "Found" : "Not Found") << endl;

    tree.print(1);
    cout << "\n" << endl;
    tree.print(0);
    cout << "\n" << endl;
    //tree.deleteNode(searchPoint8);
    cout << "\n" << endl;
    tree.printByCatchPhrase();
    cout << "\n" << endl;
    tree.printByName();
    cout << "\n" << endl;




    return 0;
}