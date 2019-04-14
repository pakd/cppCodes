#include <iostream>
#include <list>
#include <vector>
#include <queue>


using namespace std;

typedef pair<int, int> iPair;
#define INF INT_MAX

class Graph
{
public:

    int v; // no of vertices
    list< iPair> *adj; // edges with weight

    Graph(int v)
    {
        this->v = v;
        adj = new list<iPair>[v];

    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }



    void primMST()
    {

        // priority queue for getting minimum weight edge
        // min heap
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

        int src = 0;

        vector<int> dist(v, INF);

        vector<int> parent(v, -1);

        vector<bool> inMST(v, false);

        // push first source vertex
        pq.push(make_pair(0,src));
        dist[src] = 0;


        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true; // include vertex in mst

            // push all the connected edges to pq
            // also check cycle
            for(auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;

                if(inMST[v] == false && dist[v] > weight)
                {
                    dist[v] = weight;
                    pq.push(make_pair(dist[v],v));
                    parent[v] = u;
                }
            }
        }

        // Print edges of MST using parent array
    for (int i = 1; i < v; ++i)
        printf("%d -> %d\n", parent[i], i);

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

    g.primMST();


    return 0;
}
