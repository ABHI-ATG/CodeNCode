#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

// to find the number of connected components

const int n = 1e5;
vector<int> g[n];
bool vis[n];

void dfs(int vertex)
{
    if (vis[vertex])
    {
        return;
    }
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        cout << vertex << " visited " << child << endl;
        dfs(child);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i);
        cnt++;
    }

    // dfs(1);
    cout << cnt;

    return 0;
}