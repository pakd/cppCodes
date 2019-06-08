#include <iostream>
#include <list>
#include <set>
#include <vector>

class Graph
{
public:

    int v; // no of vertices
    std::list< std::pair<int, int>> *adj; // edges with weight

    Graph(int v)
    {
        this->v = v;
        adj = new std::list< std::pair<int, int>>[v];
    }

    // undirected graph
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(std::make_pair(v, w));
        adj[v].push_back(std::make_pair(u, w));
    }

    void shortestPath(int s)
    {
        // as set is sorted it will give the edge with the minimum weight
        // first = weight, second = vertex
        std::set<std::pair <int, int>> setds;

        // vector for storing answer
        std::vector<int> dist(v, INT_MAX);

        // insert first edge
        setds.insert(std::make_pair(0, s));
        dist[s] = 0;


        // while there are edges to process
        while(!setds.empty())
        {
            std::pair<int, int> temp = *setds.begin();
            setds.erase(setds.begin());

            int u = temp.second;

            // list<pair <int, int>>::iterator it;
            for(auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;

                // if there is shortest path to v via u, then update
                if(dist[v] > dist[u] + weight)
                {

                    /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                    if (dist[v] != INT_MAX)
                        setds.erase(setds.find(std::make_pair(dist[v], v)));

                    dist[v] = dist[u] + weight;
                    setds.insert(std::make_pair(dist[v], v));
                }
            }
        }

        // Print shortest distances stored in dist[]
        std::cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < v; ++i)
        {
            std::cout << i << " : " << dist[i] << std::endl;
        }

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

    g.shortestPath(0);

    return 0;
}
