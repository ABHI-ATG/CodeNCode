#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

// You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
// To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

const int t = 3;
int solve(int i, int j, int dp[][4])
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int l = solve(i - 1, j, dp);
    int r = solve(i, j - 1, dp);
    return dp[i][j] = l + r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n, m = 3;
    //     cin >> n >> m;
    //     int dp[4][4];
    //     memset(dp, -1, sizeof(dp));
    //     cout<<solve(n - 1, m - 1, dp);
    //     cout << endl;
    // }
    // tabulation
    int n, m;
    cin >> n >> m;

    int dp2[n ][m ];
    // memset(dp2, 0, sizeof(dp2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i==0&&j==0){
                dp2[i][j]=1;
            }else{
            int l = 0, r = 0;
            if (i > 0)
            {
                l = dp2[i - 1][j];
            }
            if (j > 0)
            {
                r = dp2[i][j - 1];
            }
            dp2[i][j] = l + r;
            }
        }
    }
    cout<<dp2[n-1][m-1];
    return 0;
}