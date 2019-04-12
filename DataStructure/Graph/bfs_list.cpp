#include <iostream>
#include <list>
#include <queue>

using namespace std;


class Graph
{
public:

    int v; // no of vertices
    list<int> *adj;

    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int s)
    {
        // visited array

        vector<bool> visited(v, false);


        queue<int> q;

        visited[s] = true;
        q.push(s);

        while(!q.empty())
        {
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            for(auto i=adj[curr].begin(); i!=adj[curr].end(); i++)
            {
                if(!visited[*i])
                {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }

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

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
