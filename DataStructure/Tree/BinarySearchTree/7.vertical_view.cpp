#include "bst_library.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void vertical_view(Node* root)
{
    map<int,vector<int>> hd_list;
    queue<pair<Node*,int>> Q;
    int hd = 0;
    Q.push(make_pair(root,hd));
    while(!Q.empty())
    {
        pair<Node*, int> temp = Q.front();
        Node* curr = temp.first; int hd = temp.second;
        hd_list[hd].push_back(curr->data);
        if(curr->left)
        {
            Q.push(make_pair(curr->left,hd-1));
        }
        if(curr->right)
        {
            Q.push(make_pair(curr->right,hd+1));
        }
        Q.pop();
    }


    // print map data
    for (auto x : hd_list)
    {
        for (auto y : x.second)
            cout << y << " ";
        cout << endl;
    }

}

void top_view()
{
    //same as vertical_view but print only first element in vector
}

void bottom_view()
{
    //same as vertical_view but print only last element in vector
}

int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{15,6,24,17,30,26,34};
    for(int i=0; i< dpk.size();i++)
    {
        root = myTree.insert(root, dpk[i]);
    }

    vertical_view(root);

    return 0;
}
