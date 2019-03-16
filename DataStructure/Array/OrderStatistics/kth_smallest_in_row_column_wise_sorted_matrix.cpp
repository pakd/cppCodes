#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int element;
    int row;
    int column;
};

// we have to overload operator function for comparison in priority queue
class ComparisonClass {
    public:
    bool operator() (Node A, Node B)
    {
        //comparison code here: return max in case of min heap
        return A.element > B.element;
    }
};

int kth_smallest_in_sorted_matrix(int mat[4][4], int n, int k)
{

    priority_queue<Node, vector<Node>, ComparisonClass> pq;
    for(int i=0;i<n;i++)
    {
        Node t;
        t.element = mat[0][i];
        t.row = 0;
        t.column = i;

        pq.push(t);
    }

    int count = 0;
    while(!pq.empty() && count < k)
    {
        Node top = pq.top();
        pq.pop();

        if(top.row < n-1)
        {
            Node next;
            next.element = mat[top.row + 1][top.column];
            next.row = top.row+1;
            next.column = top.column;

            pq.push(next);
        }
        cout << count+1 << "\t" << top.element << endl;
        count++;
    }
}

int main()
{
    int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
    int n = 4;
    cout << "K'th smallest element is " << kth_smallest_in_sorted_matrix(mat, 4, 8);
    return 0;
}
