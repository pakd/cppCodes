#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> iPair;

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
    std::vector<std::pair<int, iPair>> edges;

    Graph(int V)
    {
        subsets = new subset[V];

        for(int i=0; i<V; i++)
        {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }
    }

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back(std::make_pair(weight, std::make_pair(src, dest)));
    }

    // if i = subsets[i].parent then it is single element in set or root
    int find(int i)
    {
        if(subsets[i].parent != i)
        {
            // find collapsing
            subsets[i].parent = find(subsets[i].parent);
        }
        return subsets[i].parent;
    }

    // "union" keyword in c++, thats why "Union"
    void Union(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);

        // make yRoot parent
        if(subsets[xRoot].rank <= subsets[yRoot].rank)
        {
            subsets[xRoot].parent = yRoot;
            subsets[yRoot].rank++;
        }
        // make xRoot parent
        else if(subsets[xRoot].rank > subsets[yRoot].rank)
        {
            subsets[yRoot].parent = xRoot;
            subsets[xRoot].rank++;
        }
    }

    int kruskalMST()
    {
        int mst_wt = 0;

        std::sort(edges.begin(), edges.end());

        for(auto it:edges)
        {
            int xRoot = find(it.second.first);
            int yRoot = find(it.second.second);

            // if xRoot == yRoot, then cycle, don't include the edge
            if(xRoot != yRoot)
            {
                // include the edge
                std::cout << it.second.first << "->" << it.second.second << std::endl;
                mst_wt += it.first;

                Union(xRoot, yRoot);
            }
        }

        return mst_wt;
    }
};
int main()
{

    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);


    std::cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();

    std::cout << "\nWeight of MST is " << mst_wt;

    return 0;
}
