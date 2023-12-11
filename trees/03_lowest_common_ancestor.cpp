#include <bits/stdc++.h>
using namespace std;
// lowest common ancestor
// firstly storing the all the parents of all the nodes
// then traversing from node1 untill not found the root node and same as for node2
// then storing all the parents of node1,node2 and then comparing them
// when we find the last common parents of both the node then it will be the lowest common ancestor
const int n = 1e5;
vector<int> g[n];
bool visited[n];
vector<int> parents(n);

void dfs(int vertex, int parent = -1)
{
    if (visited[vertex])
    {
        return;
    }
    visited[vertex] = true;
    parents[vertex] = parent;
    for (int child : g[vertex])
    {
        dfs(child, vertex);
    }
}

vector<int> path(int x)
{
    vector<int> p;
    p.push_back(x);
    while (x != -1)
    { 
        // as we consider the root parent -1;
        p.push_back(parents[x]);
        x = parents[x];
    }
    reverse(p.begin(), p.end());
    return p;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // dfs
    // storing all the parents of all the nodes in an array
    dfs(1);
    int t = 5;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        vector<int> x_path = path(x);
        vector<int> y_path = path(y);

        int node;
        for (int i = 0; i < x_path.size(); i++)
        {
            if (x_path[i] == y_path[i])
            {
                node = x_path[i];
            }
            else
            {
                break;
            }
        }

        cout << node<<endl;
    }

    return 0;
}