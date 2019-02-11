#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{10,6,14,3,8,12,16,15,18};
    for(int i=0; i< dpk.size();i++)
    {

        root = myTree.insert(root, dpk[i]);
    }

    myTree.displayLevelOrder(root);

    return 0;
}
