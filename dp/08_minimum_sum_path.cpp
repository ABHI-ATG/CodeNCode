#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

int minimum(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int solve(int n, int m, vector<vector<int>> &v)
{
    if (n == 0 && m == 0)
    {
        return v[0][0];
    }
    if (n < 0 || m < 0)
    {
        return 10000000; // for minumum, return max values;
    }
    int left = 0;
    int up = 0;
    if (n >= 0 && m >= 0)
    {
        left = v[n][m] + solve(n - 1, m, v);
        up = v[n][m] + solve(n, m - 1, v);
    }
    return minimum(left, up);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // cout<<"hello";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
        temp.clear();
    }

    // cout << solve(n - 1, m - 1, v);

    // tabulation :
    // int dp[n + 1][m + 1];
    // memset(dp, -1, sizeof(dp));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (i == 0 && j == 0)
    //         {
    //             dp[i][j] = v[i][j];
    //         }
    //         else
    //         {
    //             int left = INT_MAX;
    //             int up = INT_MAX;
    //             if (i > 0)
    //             {
    //                 left = v[i][j] + dp[i - 1][j];
    //             }
    //             if (j > 0)
    //             {
    //                 up = v[i][j] + dp[i][j - 1];
    //             }
    //             dp[i][j] = minimum(left, up);
    //         }
    //     }
    // }
    // cout << dp[n - 1][m - 1];

    // space complexity: 
    int dp[n + 1][m + 1];
    memset(dp, -1, sizeof(dp));
    vector<int> prev(m,0);
    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m,0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                cur[j] = v[i][j];
            }
            else
            {
                int left = INT_MAX;
                int up = INT_MAX;
                if (i > 0)
                {
                    // requiring previous row j column;
                    left = v[i][j] + prev[j];
                }
                if (j > 0)
                {
                    // requiring same row j-1 column;
                    up = v[i][j] + cur[j - 1];
                }
                cur[j] = minimum(left, up);
            }
        }
        prev=cur;
    }
    cout << prev[m - 1];
    return 0;
}
