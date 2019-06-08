#include <iostream>
#include <list>
#include <stack>

/*
* Applications of topological sort
* 1. Build Systems
* 2. Advance packaging tools(apt-get in linux)
* 3. Task scheduling
* 4. Pre-requisite problems
*/

class Graph
{
public:

    int v; // no of vertices
    std::list<int> *adj;
    int *visited;

    Graph(int v)
    {
        this->v = v;
        adj = new std::list<int>[v];
        visited = new int[v];
        for(int i=0; i<v; i++)
        {
            visited[i] = false;
        }
    }

    // directed graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void topologicalSortUtil(int s, std::stack<int>& st)
    {
        visited[s] = true;

        for(auto i : adj[s])
        {
            if(!visited[i])
            {
                topologicalSortUtil(i, st);
            }
        }

        // after complete processing push to stack
        st.push(s);
    }


    void topologicalSort()
    {
        std::stack<int> st;

        // call topologicalSortUtil for every vertex
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                topologicalSortUtil(i, st);
            }
        }

        while(!st.empty())
        {
            std::cout << st.top() << " ";
            st.pop();
        }

    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    std::cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}
