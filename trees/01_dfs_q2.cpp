#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

// to find number of cycles

const int n = 1e5;
vector<int> g[n];
bool vis[n];

int cycle = 0;

void dfs(int vertex, int parent)
{
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        cout<<vertex<<" visited "<<child<<" parent "<<parent<<" cycle "<<cycle<<endl;
        if (vis[child] == true && child == parent)
        {
            continue;
        }
        if (vis[child] == true)
        {
            cycle++;
            // cout<<cycle;
            continue;
        }
        dfs(child, vertex);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
    dfs(1, 4);
    cout << cycle;
    return 0;
}