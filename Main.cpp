#include "MyRBT.h"
#include <iostream>
using namespace std;

void printmenu();
void menu(MyRBT<int> tree);

int main()
{
    MyRBT<int> tree;
    /*tree.insertValue(7);
    tree.insertValue(3);
    tree.insertValue(18);
    tree.insertValue(22);
    tree.insertValue(10);
    tree.insertValue(8);
    tree.insertValue(11);
    tree.insertValue(26);*/

    menu(tree);

    return 0;
}

void printmenu()
{
    cout << "\n**********************************" << endl;
    cout << "               Menu               " << endl;
    cout << "**********************************" << endl;
    cout << endl;
    cout << "Choice 1 : Insert Value in Tree" << endl;
    cout << "Choice 2 : Delete Value" << endl;
    cout << "Choice 3 : Print Tree in Inoreder" << endl;
    cout << "Choice 4 : Print Tree in Preorder" << endl;
    cout << "choice 5 : Print Tree in Postorder" << endl;
    cout << "Choice 6 : Print minimum value" << endl;
    cout << "Choice 7 : Print maximum value" << endl;
    cout << "Choice 8 : Search a value" << endl;
    cout << "Choice 9 : Calculate Height of Tree" << endl;
    cout << "Choice 10 : Find Successor" << endl;
    cout << "Choice 11: Find Predecessor" << endl;
    cout << "Choice 12: Exit" << endl;
    cout << endl;
}

void menu(MyRBT<int> tree)
{
    int choice = 5;
    do
    {
        int value = 0;
        printmenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Value to insert: ";
            cin >> value;
            tree.insertValue(value);
            break;

        case 2:
            cout << "Enter Value to delete: ";
            cin >> value;
            tree.deleteValue(value);
            break;

        case 3:
            cout << "Tree in Inorder: ";
            tree.displayInorder(cout);
            break;

        case 4:
            cout << "Tree in Preorder: ";
            tree.displayPreorder(cout);
            break;

        case 5:
            cout << "Tree in Postorde: ";
            tree.displayPostorder(cout);
            break;

        case 6:
            tree.minValue();
            break;

        case 7:
            tree.maxValue();
            break;

        case 8:
            cout << "Enter the Value you want to Search: ";
            cin >> value;
            tree.searchValue(value);
            break;

        case 9:
            value = tree.calculateHeight(tree.getRoot());
            cout << "Height of Tree: " << value << endl;
            break;

        case 10:
            cout << "Enter Value: ";
            cin >> value;
            tree.successor(value);
            break;

        case 11:
            cout << "Enter Value: ";
            cin >> value;
            tree.predecessor(value);
            break;

        case 12:
            cout << "Exiting....." << endl;
            break;
        }
    } while (choice != 11);
}