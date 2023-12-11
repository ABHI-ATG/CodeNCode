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

int main()
{

    Welcome;
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> g(n);
    f(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        // f(i,0,m) -- traversing all edges
        for (int i = 0; i < n + 1; i++)
        {
            for (auto it : g[i])
            {
                if (dist[i] != INT_MAX && dist[it.first] > dist[i] + it.second)
                {
                    dist[it.first] = dist[i] + it.second;
                }
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (auto it : g[i])
        {
            if (dist[i] != INT_MAX && dist[it.first] > dist[i] + it.second)
            {
                cout<<"NEGATIVE WEIGHT CYCLE\n";
                return;
            }
        }
    }

    // answer

    return 0;
}