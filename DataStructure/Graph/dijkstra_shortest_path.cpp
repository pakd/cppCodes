#include <iostream>
#include <list>
#include <set>
#include <vector>


using namespace std;


class Graph
{
public:

    int v; // no of vertices
    list< pair<int, int>> *adj; // edges with weight

    Graph(int v)
    {
        this->v = v;
        adj = new list< pair<int, int>>[v];

    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }



    void shortestPath(int s)
    {
        // as set is sorted it will give the edge with the minimum weight
        // first = weight, second = vertex
        set<pair <int, int>> setds;

        // vector for storing answer
        vector<int> dist(v, INT_MAX);

        // insert first edge
        setds.insert(make_pair(0, s));
        dist[s] = 0;


        // while there are edges to process
        while(!setds.empty())
        {
            pair<int, int> temp = *setds.begin();
            setds.erase(setds.begin());

            int u = temp.second;

            // list<pair <int, int>>::iterator it;
            for(auto it = adj[u].begin(); it!=adj[u].end(); it++)
            {
                pair<int, int> t = *it;
                int v = t.first;
                int weight = t.second;

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
                        setds.erase(setds.find(make_pair(dist[v], v)));

                    dist[v] = dist[u] + weight;
                    setds.insert(make_pair(dist[v], v));

                }
            }
        }

        // Print shortest distances stored in dist[]
        cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < v; ++i)
        {
            cout << i << " : " << dist[i] << endl;
        }

    }
};

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
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
