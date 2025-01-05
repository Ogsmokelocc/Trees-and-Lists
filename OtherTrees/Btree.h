#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Node
{
public:
    string name;
    string catchphrase;
    Node *Left, *Right;

    Node(string n, string c) : name(n), catchphrase(c), Left(nullptr), Right(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    // Insert by name
    void insertByName(string name, string catchphrase)
    {
        root = insertByNameRec(root, name, catchphrase);
    }

    // Insert by catchphrase
    void insertByCatchphrase(string name, string catchphrase)
    {
        root = insertByCatchphraseRec(root, name, catchphrase);
    }

    // Delete by name
    void deleteByName(string name)
    {
        root = deleteByNameRec(root, name);
    }

    // Delete by catchphrase
    void deleteByCatchphrase(string catchphrase)
    {
        root = deleteByCatchphraseRec(root, catchphrase);
    }

    // Print in order by name
    void printByName()
    {
        cout << "In-order by Name: ";
        inOrderByName(root);
        cout << endl;
    }

    // Print in order by catchphrase
    void printByCatchphrase()
    {
        cout << "In-order by Catchphrase: ";
        inOrderByCatchphrase(root);
        cout << endl;
    }

private:
    Node *insertByNameRec(Node *node, string name, string catchphrase)
    {
        if (node == nullptr)
            return new Node(name, catchphrase);
        if (name < node->name)
        {
            node->Left = insertByNameRec(node->Left, name, catchphrase);
        }
        else
        {
            node->Right = insertByNameRec(node->Right, name, catchphrase);
        }
        return node;
    }

    Node *insertByCatchphraseRec(Node *node, string name, string catchphrase)
    {
        if (node == nullptr)
            return new Node(name, catchphrase);
        if (catchphrase < node->catchphrase)
        {
            node->Left = insertByCatchphraseRec(node->Left, name, catchphrase);
        }
        else
        {
            node->Right = insertByCatchphraseRec(node->Right, name, catchphrase);
        }
        return node;
    }

    Node *deleteByNameRec(Node *node, string name)
    {
        if (node == nullptr)
            return node;

        if (name < node->name)
        {
            node->Left = deleteByNameRec(node->Left, name);
        }
        else if (name > node->name)
        {
            node->Right = deleteByNameRec(node->Right, name);
        }
        else
        {
            if (node->Left == nullptr)
            {
                Node *temp = node->Right;
                delete node;
                return temp;
            }
            else if (node->Right == nullptr)
            {
                Node *temp = node->Left;
                delete node;
                return temp;
            }
            Node *temp = minValueNode(node->Right);
            node->name = temp->name;
            node->catchphrase = temp->catchphrase;
            node->Right = deleteByNameRec(node->Right, temp->name);
        }
        return node;
    }

    Node *deleteByCatchphraseRec(Node *node, string catchphrase)
    {
        if (node == nullptr)
            return node;

        if (catchphrase < node->catchphrase)
        {
            node->Left = deleteByCatchphraseRec(node->Left, catchphrase);
        }
        else if (catchphrase > node->catchphrase)
        {
            node->Right = deleteByCatchphraseRec(node->Right, catchphrase);
        }
        else
        {
            if (node->Left == nullptr)
            {
                Node *temp = node->Right;
                delete node;
                return temp;
            }
            else if (node->Right == nullptr)
            {
                Node *temp = node->Left;
                delete node;
                return temp;
            }
            Node *temp = minValueNode(node->Right);
            node->name = temp->name;
            node->catchphrase = temp->catchphrase;
            node->Right = deleteByCatchphraseRec(node->Right, temp->catchphrase);
        }
        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->Left != nullptr)
        {
            current = current->Left;
        }
        return current;
    }

    void inOrderByName(Node *node)
    {
        if (node != nullptr)
        {
            inOrderByName(node->Left);
            cout << " [" << node->name << ", " << node->catchphrase << "] : ";
            inOrderByName(node->Right);
        }
    }

    void inOrderByCatchphrase(Node *node)
    {
        if (node != nullptr)
        {
            inOrderByCatchphrase(node->Left);
            cout << " [" << node->name << ", " << node->catchphrase << "] :";
            inOrderByCatchphrase(node->Right);
        }
    }
};

// Function to read villagers from the CSV file
void readVillagersFromFile(const string &filename, BinaryTree &nameTree, BinaryTree &catchphraseTree)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    getline(file, line);
    // Skip header row

    while (getline(file, line))
    {
        istringstream stream(line);
        string name, catchphrase;

        // parse name and catchphrase columns
        getline(stream, name, ','); // Name
        for (int i = 0; i < 5; ++i)
            stream.ignore(256, ',');       // Skip species to birthday
        getline(stream, catchphrase, ','); // Catchphrase

        // Insert into both trees
        nameTree.insertByName(name, catchphrase);
        catchphraseTree.insertByCatchphrase(name, catchphrase);
    }
    file.close();
}

// Function to display menu
void menu(BinaryTree &nameTree, BinaryTree &catchphraseTree)
{
    int choice;
    string name, catchphrase;

    do
    {
        cout << "\nMenu:\n";
        cout << "Insert a node: \n";
        cout << "Print in order by name: \n";
        cout << "Print in order by catchphrase: \n";
        cout << "Delete by name: \n";
        cout << "Delete by catchphrase: \n";
        cout << "Exit: \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter catchphrase: ";
            getline(cin, catchphrase);

            nameTree.insertByName(name, catchphrase);
            catchphraseTree.insertByCatchphrase(name, catchphrase);
            cout << "Node inserted: \n";
            break;

        case 2:
            nameTree.printByName();
            break;

        case 3:
            catchphraseTree.printByCatchphrase();
            break;

        case 4:
            cout << "Enter name to delete: ";
            cin.ignore();
            getline(cin, name);
            nameTree.deleteByName(name);
            cout << "Node with name '" << name << "' deleted.\n";
            break;

        case 5:
            cout << "Enter catchphrase to delete: ";
            cin.ignore();
            getline(cin, catchphrase);
            catchphraseTree.deleteByCatchphrase(catchphrase);
            cout << "Node with catchphrase '" << catchphrase << "' deleted.\n";
            break;

        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}
