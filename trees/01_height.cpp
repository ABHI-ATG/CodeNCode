#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// height and depth of a tree

const int n = 1e5;
vector<int> g[n];
vector<int> vis(n);
vector<int> depth(n);

void dfs(int vertex,int dep)
{
    if (vis[vertex])
    {
        return;
    }
    depth[vertex]=dep;
    dep++;
    vis[vertex] = 1;
    // 
    for (int child : g[vertex])
    {
        //
        // cout<<vertex<<" visited "<<child<<endl;
        dfs(child,dep);
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

    dfs(1,0);
    for(int i=1;i<=v;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=1;i<=v;i++){
        cout<<depth[i]<<" ";
    }
    return 0;
}