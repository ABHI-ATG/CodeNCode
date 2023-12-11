#include <bits/stdc++.h>
using namespace std;
/* Atg */
// time complexity : n^2;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int parents[n + 1];
    int mst[n + 1];
    int key[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        key[i] = INFINITY;
        parents[i] = -1;
        mst[i] = 0;
    }

    // priority implementation to get the minimal ele
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    parents[1] = -1;
    key[1] = 0;
    pq.push({0, 1}); //{wight,vertex}

    for (int i = 1; i < n; i++) // n-1 edges
    {
        int v = pq.top().second;
        pq.pop();

        mst[v] = 1;
        for (auto it : graph[v])
        {
            int node = it.first;
            int weight = it.second;
            if (mst[node] == false && key[node] > weight)
            {
                parents[node] = v;
                key[node] = weight;
                pq.push({key[node],node});
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << parents[i] << " " << i << " " << key[i] << endl;
    }

    return 0;
}
