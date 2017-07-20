#include <bits/stdc++.h>
using namespace std;
int v = 7;
int cost[15][15], visited[15];
void dfs(int vert)
{
    visited[vert] = 1;
    for(int i=1;i<=v;i++)
    {
        if(cost[vert][i] == 1  && visited[i] == 0)
        {
            cout << i << " ";
            dfs(i);
        }
    }
}
int main()
{
    int e = 6;
    int initial = 1;
    pair<int,int> edges[7];
    edges[1] = make_pair(1,2);
    edges[2] = make_pair(2,3);
    edges[3] = make_pair(2,4);
    edges[4] = make_pair(3,5);
    edges[5] = make_pair(4,7);
    edges[6] = make_pair(7,6);


    for(int k=1;k<=e;k++)
    {
        cost[edges[k].first][edges[k].second] = 1;
        cost[edges[k].second][edges[k].first] = 1;
    }

    cout << initial << " ";
    dfs(initial);
}
