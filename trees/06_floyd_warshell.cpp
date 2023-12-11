#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// all pair shortest path;
// all levels are added to get the shortest path
// so we can find the shortest path by removing the edge
const int n = 1e2 + 10;
int d[n][n];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                d[i][j] = 0;
            }
            else
            {
                d[i][j] = -1;
            }
        }
    }

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        d[v1][v2] = w;
    }


    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (d[i][k] == -1 || d[k][j] == -1)
                {
                    continue;
                }
                else
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (d[i][j] == -1)
            {
                cout << "I ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}