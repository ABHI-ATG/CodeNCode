// Jai Shree Ram
#include <bits/stdc++.h>
using namespace std;

// Atg
#define f(i, m, n) for (int i = m; i < n; i++)
#define f2(i, n, m) for (int i = n; i >= m; i--)
#define Welcome                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INDIA 1000000007
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
#define array2         \
    int n;             \
    cin >> n;          \
    int x;             \
    cin >> x;          \
    int arr[n];        \
    f(i, 0, n)         \
    {                  \
        cin >> arr[i]; \
    }
#define str   \
    string s; \
    cin >> s;
#define dbg cout << "Bharat\n";
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define minus cout << "-1\n";
#define endl "\n"
#define ll long long
#define all(v) v.begin(), v.end()

void atg();

// calculating the levels and nodes at interval of 2^i (nlogn)
void dfs(int s, vector<int> &level, vector<vector<int>> &node, vector<int> &vis, int par, vector<vector<int>> &graph, int &ln)
{
    if (vis[s])
    {
        return;
    }
    vis[s] = 1;
    level[s] = level[par] + 1;

    node[s][0] = par;
    for (int i = 1; i < ln; i++)
    {
        node[s][i] = node[node[s][i - 1]][i - 1];
    }

    for (auto it : graph[s])
    {
        dfs(it, level, node, vis, s, graph, ln);
    }
}

int lca(int u, int v, vector<vector<int>> &node, vector<int> &level, int &ln)
{
    if (level[u] < level[v])
    {
        swap(u, v);
    }

    int dif = level[u] - level[v];
    for (int i = 0; i < ln; i++)
    {
        if ((1LL << i) & dif)
        {
            u = node[u][i];
        }
    }

    if (u == v)
    {
        return u;
    }

    int tmp = 0;
    for (int i = ln - 1; i >= 0; i--)
    {
        if (node[u][i] == node[v][i])
        {
            tmp = node[u][i];
        }
    }

    return tmp;
}

// Atg
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Welcome;
    int n = 1;
    // cin >> n;
    while (n--)
    {
        atg();
    }
}

/*



        *         *  *  *  *  *         *  *  *
      *   *             *             *
    *       *           *            *      *  *  *
  *  *  *  *  *         *             *          *
*              *        *                *  *  *




*/

void atg()
{

    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    f(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ln = log2(n);
    vector<vector<int>> node(n + 1, vector<int>(ln));
    vector<int> level(n + 1), vis(n + 1, 0);

    level[0] = -1;
    dfs(1, level, node, vis, 0, graph, ln);

    for (auto it : node)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    cout << endl;

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v, node, level, ln) << endl;
    }
}
// Atg