#include <iostream>
#include <list>

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
        for(int i=0; i<v; i++)
        {
            visited[i] = false;
        }
    }

    // undirected graph
    void addEdge(int u, int w)
    {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    bool isCycleDFS(int s, int parent)
    {
        cout << s << " " << parent << endl;
        visited[s] = true;

        for(auto i : adj[s])
        {
            if(!visited[i])
            {
                // s is parent of i
                if(isCycleDFS(i, s))
                {
                    return true;
                }
            }

            // If an adjacent is visited and not parent of current vertex,
            // then there is a cycle.
            else if(i != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool checkCycle()
    {
        for(int i=0; i<v; i++)
        {
            if(!visited[i])
            {
                if(isCycleDFS(i, -1))
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
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.checkCycle()? cout << "Graph contains cycle\n":
                          cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.checkCycle()? cout << "Graph contains cycle\n":
                          cout << "Graph doesn't contain cycle\n";


    return 0;
}
