#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> iPair;

class Graph
{

public:

    int *dist;
    int V;
    std::vector<std::pair<int, iPair>> edges;

    Graph(int V)
    {
        this->V = V;
        dist = new int[V];

        // Step 1: Initialize distances from src to all other vertices
        // as INFINITE
        for(int i=0; i<V; i++)
        {
            dist[i] = INT_MAX;
        }

    }

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back(std::make_pair(weight, std::make_pair(src, dest)));
    }

    void BellmanFord(int src)
    {
        dist[src] = 0;

        // Step 2: Relax all edges |V| - 1 times. A simple shortest
        // path from src to any other vertex can have at-most |V| - 1
        // edges
        for (int i = 1; i <= V-1; i++)
        {
            for (auto j : edges)
            {
                int u = j.second.first;
                int v = j.second.second;
                int weight = j.first;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                }

            }
        }

        // Step 3: check for negative-weight cycles.  The above step
        // guarantees shortest distances if graph doesn't contain
        // negative weight cycle.  If we get a shorter path, then there
        // is a cycle.
        for (auto j : edges)
        {
            int u = j.second.first;
            int v = j.second.second;
            int weight = j.first;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                std::cout << "Graph contains negative weight cycle";
            }

        }

        printArr();

    }

    void printArr()
    {
        std::cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < V; ++i)
        {
            std::cout << i << "\t" << dist[i] << std::endl;
        }
    }

};
int main()
{

    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.BellmanFord(0);

    return 0;
}
