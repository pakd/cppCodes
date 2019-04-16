#include <iostream>
#include <vector>
using namespace std;

struct subset
{
    int parent;
    int rank;
};

class Graph
{

public:

    // first = parent
    // second = rank
    subset *subsets;

    Graph(int V)
    {
        subsets = new subset[V];

        for(int i=0; i<V; i++)
        {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

    }

    // if i = subsets[i].parent then it is single element in set or root
    int find(int i)
    {
        if(subsets[i].parent != i)
        {
            find(subsets[i].parent);
        }
        return subsets[i].parent;
    }

    // "union" keyword in c++, thats why "Union"
    void Union(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);

        // make yRoot parent
        if(subsets[xRoot].rank < subsets[yRoot].rank)
        {
            subsets[xRoot].parent = yRoot;
            // subsets[yRoot].rank++;
        }
        // make xRoot parent
        else if(subsets[xRoot].rank > subsets[yRoot].rank)
        {
            subsets[yRoot].parent = xRoot;
            // subsets[xRoot].rank++;
        }
        // if both ranks equal, make anyone parent
        // lets make xRoot parent
        else
        {
            subsets[yRoot].parent = xRoot;
            subsets[xRoot].rank++;
        }
    }

    bool isCycle(vector<pair<int, int>> &edges)
    {
        for(auto i : edges)
        {
            int x = find(i.first);
            int y = find(i.second);
            // cout << i.first << " " << i.second << endl;

            if(x == y)
            {
                return true;
            }
            Union(x, y);
        }
        return false;
    }
};
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(0, 2));

    int V = 3;
    Graph g(V);

    if (g.isCycle(edges))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

    return 0;
}
