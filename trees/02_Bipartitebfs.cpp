#include <bits/stdc++.h>
using namespace std;
/* Atg */

bool bipartite_bfs(vector<vector<int>> &graph, int source, vector<int> &vis, vector<int> &dis, int col, int par)
{
    queue<int> q;
    q.push(source);
    dis[source] = col;

    while (!q.empty())
    {
        int temp = q.front();
        if (dis[temp])
        {
            col = 0;
        }
        else
        {
            col = 1;
        }
        q.pop();
        for (auto it : graph[temp])
        {
            if (dis[it] == -1)
            {
                q.push(it);
                dis[it] = col;
            }
            else
            {
                if (dis[it] != col)
                {
                    return false;
                }
            }
        }
        
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // cout<<"hello world";
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    vector<int> dis(n + 1, -1);

    cout << bipartite_bfs(graph, 1, vis, dis, 1, -1);

    return 0;
}
