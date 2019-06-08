#include <iostream>
#include <list>
#include <stack>

class Graph
{
public:
    int V;
    std::list<int> *adj;
    int *visited;


    // initialization
    Graph(int v)
    {
        this->V = v;
        adj = new std::list<int>[v];
        visited = new int[V];

        for(int i=0; i<v; i++)
        {
            visited[i] = false;
        }
    }

    void addEdge(int start, int end)
    {
        adj[start].push_back(end);
    }

    void topologicalSortUtil(int s, std::stack<int>& st)
    {
        visited[s] = true;

        for(auto it : adj[s])
        {
            if(!visited[it])
            {
                topologicalSortUtil(it, st);
            }
        }

        // done processing, push to stack
        st.push(s);
    }

    void topologicalSort()
    {
        std::stack<int> st;

        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                topologicalSortUtil(i, st);
            }
        }

        while(!st.empty())
        {
            std::cout << char(st.top() + 'a') << " ";
            st.pop();
        }
    }
};

void printOrder(std::string *arr, int n, int alpha)
{

    Graph g(alpha);
    for(int i=0; i<n; i++)
    {
        int len = arr[i].length();
        for(int j=0; j<len-1; j++)
        {
            char tempS = arr[i][j];
            char tempE = arr[i][j+1];

            g.addEdge(tempS - 'a', tempE - 'a');
        }
    }

    g.topologicalSort();
}

int main()
{
    //std::string words[] = {"baa", "abcd", "abca", "cab", "cad"}; // ans can be multiple
    std::string words[] = {"ccee", "cdbb", "bae", "aee", "daa"}; // alpha = 5 -> cdbae
    int size = 5;

    // lets assume 5 starting alphabets only
    printOrder(words, size, 5);

    return 0;
}


