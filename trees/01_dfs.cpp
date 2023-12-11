#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

const int n = 1e5;
vector<int> g[n];
vector<int> vis(n);

void dfs(int vertex)
{
    if (vis[vertex])
    {
        return;
    }
    vis[vertex] = 1;
    // 
    for (int child : g[vertex])
    {
        //
        cout<<vertex<<" visited "<<child<<endl;
        dfs(child);
        //
    }
    //
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

    dfs(1);

    return 0;
}