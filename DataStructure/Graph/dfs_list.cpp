#include <iostream>
#include <list>
#include <queue>

using namespace std;


class Graph
{
public:

    int v; // no of vertices
    list<int> *adj;
    int *visited;

    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
        visited = new int[v];
        for(int i=0;i<v;i++)
        {
            visited[i] = false;
        }
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }



    void DFS(int s)
    {
        // visited array

        visited[s] = true;

        cout << s << " ";

        for(auto i = adj[s].begin(); i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                DFS(*i);
            }
        }

    }
};

int main()
{
    // Create a graph given in the above diagram
    /*Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);*/  // DFS : 2 0 1 3

    Graph g(6);
    g.addEdge(2, 0);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 5);
    g.addEdge(1, 4); // DFS : 2 0 1 5 4 3



    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}
