#include <iostream>
using namespace std;
#include "Binary_Tree.cpp"

int main()
{
    try
    {
        BinTree<char> T;
        cout << "PreOrder traversal of the tree:" << endl;
        T.PreOrder();
    }
    catch (exception &e)
    {
        cout << "An error occurred: " << e.what() << endl;
    }

    // Use a more portable way to pause the system.
    cout << "Press Enter to exit..." << endl;
    cin.get();
    cin.get(); // This ensures the window stays open until the user presses enter.
    return 0;
}
