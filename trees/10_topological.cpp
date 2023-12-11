#include <bits/stdc++.h>
using namespace std;
/* Atg */

/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

For example, a topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph. For example, another topological sorting of the following graph is “4 5 2 3 1 0”. The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).
 */


void topo_dfs(vector<vector<int>> &graph, int source, vector<int> &vis, vector<int> &st)
{
    if (vis[source])
    {
        return;
    }
    vis[source] = 1;
    for (auto it : graph[source])
    {
        topo_dfs(graph, it, vis, st);
    }
    st.push_back(source);
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
        // graph[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    vector<int> st;

    topo_dfs(graph, 1, vis, st);
    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i] << " ";
    }
    return 0;
}
