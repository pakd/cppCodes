#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{15,6,24,17,30,26,34};
    for(int i=0; i< dpk.size();i++)
    {

        root = myTree.insert(root, dpk[i]);
    }

    myTree.displayInorder(root);

    int height = myTree.getHeight(root);

    cout << endl;
    cout << "Height of the tree:"  << height;
    cout << endl;

    return 0;
}
