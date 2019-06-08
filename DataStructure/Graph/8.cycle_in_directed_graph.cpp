#include <iostream>
#include <list>
#include <vector>


enum colors {
    White = 0,
    Gray = 1,
    Black = 2
};

class Graph
{
public:

    int v; // no of vertices
    std::list<int> *adj;

    Graph(int v)
    {
        this->v = v;
        adj = new std::list<int>[v];
    }

    // directed graph
    void addEdge(int u, int w)
    {
        adj[u].push_back(w);
    }

    bool isCycleDFS(int s, std::vector<colors>& Color)
    {
        // put in gray color , currently visited nodes
        Color[s] = Gray;

        for(auto i : adj[s])
        {
            // cycle is there if neighbor is gray
            if(Color[i] == Gray)
            {
                return true;
            }


            // check for further descendants
            else if(Color[i] == White && isCycleDFS(i, Color))
            {
                return false;
            }
        }

        // completely visited, descendant also visited
        Color[s] = Black;

        return false;
    }

    bool checkCycle()
    {

        // initially all white color
        std::vector<colors> Color(v, White);

        for(int i=0; i<v; i++)
        {
            if(Color[i] == White)
            {
                if(isCycleDFS(i, Color))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.checkCycle())
        std::cout << "Graph contains cycle";
    else
        std::cout << "Graph doesn't contain cycle";

        std::cout << std::endl;

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    if (g2.checkCycle())
        std::cout << "Graph contains cycle";
    else
        std::cout << "Graph doesn't contain cycle";


    return 0;
}
