#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

struct Node
{
    int sum;
    int indexA;
    int indexB;
};


// we have to overload operator function for comparison in priority queue
class ComparisonClass {
    public:
    bool operator() (Node A, Node B)
    {
        //comparison code here: return max in case of min heap
        return A.sum < B.sum;
    }
};


void KMaxCombinations(int *arrA, int n, int *arrB, int m, int k)
{
    std::priority_queue<Node, std::vector<Node>, ComparisonClass> pq;
    std::set<std::pair<int, int>> s;

    Node first;
    first.sum = arrA[n-1] + arrB[m-1];
    first.indexA = n - 1;
    first.indexB = m - 1;
    pq.push(first);
    std::pair<int, int> t = {n-1, m-1};
    s.insert(t);


    int count = 0;

    while(count < k)
    {
        Node topE = pq.top();
        pq.pop();

        Node left, right;

        std::pair <int, int> leftPair = {topE.indexA-1, topE.indexB};
        if(topE.indexA >0 && topE.indexB > 0 && s.find(leftPair)==s.end())
        {
            left.sum = arrA[topE.indexA-1] + arrB[topE.indexB];
            left.indexA = topE.indexA -1;
            left.indexB = topE.indexB;
            pq.push(left);
        }

        std::pair <int, int> rightPair = {topE.indexA, topE.indexB - 1};
        if(topE.indexA >0 && topE.indexB > 0 && s.find(rightPair)==s.end())
        {
            right.sum = arrA[topE.indexA] + arrB[topE.indexB - 1];
            right.indexA = topE.indexA ;
            right.indexB = topE.indexB - 1;
            pq.push(right);
        }
        std::cout << count+1 << " "  <<arrA[topE.indexA] << "+" << arrB[topE.indexB] << "=" << topE.sum << std::endl;
        count++;
    }
}

int main()
{
    int arrA[] = { 1, 4, 2, 3 };
    int n = 4;
    std::sort(arrA, arrA + n);


    int arrB[] = { 2, 5, 1, 6 };
    int m = 4;
    std::sort(arrB, arrB + m);

    int K = 4;
    KMaxCombinations(arrA, n, arrB, m, K);
    return 0;
}
