#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

int n;
int solve(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int s = solve(i + 1, j, v, dp);
    int r = solve(i + 1, j + 1, v, dp);
    return dp[i][j] = v[i][j] + min(s, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    cin >> n;
    vector<vector<int>> v, dp(n);
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < cnt; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
            dp[i].push_back(-1);
        }
        cnt++;
        v.push_back(temp);
        temp.clear();
    }
    // 
    
    // cout << solve(0, 0, v, dp)<<endl;;s

    // tabulation :
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < cnt - 2; j++)
        {
            int left = INT_MAX;
            int up = INT_MAX;
            left = v[i + 1][j];
            up = v[i + 1][j + 1];
            dp[i][j] = v[i][j] + min(left, up);
            v[i][j]=dp[i][j];
        }
        cnt--;
    }

    // cnt=1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < cnt; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    //     cnt++;

    // }
    cout << dp[0][0];

    return 0;
}
