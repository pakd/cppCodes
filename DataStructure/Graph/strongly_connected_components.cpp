#include <iostream>
#include <list>
#include <stack>

using namespace std;
/*
We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. Following is detailed Kosaraju’s algorithm.
1) Create an empty stack ‘S’ and do DFS traversal of a graph.
 In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack.
  In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty.
Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)).
 The DFS starting from v prints strongly connected component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).
*/

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

    // directed graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void DFSUtilStack(int s, stack<int> &st)
    {
        // visited array
        visited[s] = true;

        for(auto i : adj[s])
        {
            if(!visited[i])
            {
                DFSUtilStack(i, st);
            }
        }
        st.push(s);
    }

    void DFSUtil(int s)
    {
        // visited array
        visited[s] = true;
        cout << s << " " ;
        for(auto i : adjT[s])
        {
            if(!visited[i])
            {
                DFSUtil(i);
            }
        }
    }

    void StrongConnectedComponents()
    {
        stack<int> st;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                DFSUtilStack(i, st);
            }
        }

        // take transpose of graph
        transposeGraph();

        for(int i=0; i<v; i++)
        {
            visited[i] = false;
        }

        while(!st.empty())
        {
            int stTop = st.top();
            st.pop();
            if(!visited[stTop])
            {
                DFSUtil(stTop);
                cout << endl;
            }
        }
    }

    list<int> *adjT;

    void transposeGraph()
    {
        adjT = new list<int>[v];
        for(int i=0;i<v;i++)
        {
            for(auto j : adj[i])
            {
                adjT[j].push_back(i);
            }
        }
    }
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.StrongConnectedComponents();

    return 0;
}
