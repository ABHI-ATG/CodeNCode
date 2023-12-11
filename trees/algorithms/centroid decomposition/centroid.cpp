#include <bits/stdc++.h>
using namespace std;
/* Atg */
#define f(i, m, n) for (int i = m; i < n; i++)
#define Welcome                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define number \
    int n;     \
    cin >> n;
#define array          \
    int n;             \
    cin >> n;          \
    int arr[n];        \
    f(i, 0, n)         \
    {                  \
        cin >> arr[i]; \
    }
#define str   \
    string s; \
    cin >> s;
typedef long long ll;

/*
Centroid Decomposition :
    centroid of a tree is a node whose no of node in each sub-tree have less than n/2;
        - there always exist a centroid of a tree;
    properties :
    - height is atmost log(n);
    - distance dist(a-b) (original tree) is equal to dist(a-c)+dist(b-c) (centroid tree), where c is lca of a and b;
    - we decompost the given tree into o(nlogn) different paths (set)
        such that any path (n*(n-1))/2 is the concatenation of different path from this nlogn path ;

    nlogn path : summation of paths (centroid root to its sub-tee nodes)
*/

vector<vector<int>> g(200005);
int nn;
vector<int> sz_sub(200005, 0);
vector<int> vis(200005, 0);
vector<vector<int>> tree(200005);

int dfs(int s, int par)
{
    sz_sub[s] = 1;
    nn++;
    for (auto it : g[s])
    {
        if (it != par && vis[it] == 0)
        {
            sz_sub[s] += dfs(it, s);
        }
    }
    return sz_sub[s];
}

int centroid(int s)
{
    dfs(s, s);
    // f(i, 1, 17)
    // {
    //     cout << sz_sub[i] << " ";
    // }
    // cout << endl;
    // cout << nn << "\n";

    while (1)
    {
        int tmp = 0;
        sz_sub[s] = 0;
        for (auto it : g[s])
        {
            if (sz_sub[it] > nn / 2 && vis[it] == 0)
            {
                tmp = 1;
                s = it;
                break;
            }
        }
        if (tmp == 0)
        {
            break;
        }
    }

    return s;
}

int decompose(int src)
{
    nn = 0;
    int cent = centroid(src);

    vis[cent] = 1;

    for (auto it : g[cent])
    {
        if (vis[it] == 0)
        {
            int node = decompose(it);
            tree[cent].push_back(node);
        }
    }
    return cent;
}

int main()
{

    Welcome;
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    f(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int node = decompose(1);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " : ";
    //     for (auto it : tree[i])
    //     {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}