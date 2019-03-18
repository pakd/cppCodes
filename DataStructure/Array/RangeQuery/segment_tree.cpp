#include <iostream>
using namespace std;

void constructSTUtil(int *arr, int *tree, int start, int end, int treeNode )
{
    if(start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end)/2;

    constructSTUtil(arr, tree, start, mid, 2*treeNode + 1);
    constructSTUtil(arr, tree, mid + 1, end, 2*treeNode + 2);

    tree[treeNode] = tree[2*treeNode + 1] + tree[2*treeNode +2];
    return;
}


int findRangeSum(int *tree, int qStart, int qEnd, int start, int end, int treeNode)
{
    if(qStart <= start && qEnd >= end) // case of total overlap, current range lies inside query range
    {
        return tree[treeNode];
    }

    if( start > qEnd || end < qStart ) // case of no overlap
    {
        return 0;
    }

    // case of partial overlap, calculate recursively

    int mid = (start+end)/2;

    int leftSubtree = findRangeSum(tree, qStart, qEnd, start, mid, 2*treeNode + 1);
    int rightSubtree = findRangeSum(tree, qStart, qEnd, mid + 1, end, 2*treeNode + 2);

    return (leftSubtree + rightSubtree);


}

void updateValue(int *tree, int index, int diff, int start, int end, int treeNode)
{
    if( index < start || index > end ) // case of no overlap
    {
        return ;
    }

    tree[treeNode] += diff;

    // case of partial overlap, calculate recursively
    if(start != end)
    {
        int mid = (start+end)/2;
        updateValue(tree, index, diff, start, mid, 2*treeNode + 1);
        updateValue(tree, index, diff, mid + 1, end, 2*treeNode + 2);
    }
}


int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *tree = new int[2*n];

    constructSTUtil(arr, tree, 0, n-1, 0);

    for(int i=0;i<2*n-1;i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    cout << findRangeSum(tree, 4, 6, 0, n-1, 0) << endl;

    int index = 5;
    arr[5] = 8;
    int diff = 2; // curr_value - old value;

    updateValue(tree, index, diff, 0 , n-1, 0);

    cout << findRangeSum(tree, 4, 6, 0, n-1, 0) << endl;

    return 0;
}
