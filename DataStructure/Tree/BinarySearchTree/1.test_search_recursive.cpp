#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{13, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18};
    for(int i=0; i< dpk.size();i++)
    {

        root = myTree.insert(root, dpk[i]);
    }

    Node* s = myTree.search(root, 8);
    //Node* s = myTree.search(root, 19);
    if(s) cout << s->data;
    return 0;
}
