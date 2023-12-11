#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// Ninja Training :
// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

/*
Input:
2
3
1 2 5
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90

Output:
11
210
*/

int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int solve(int arr[][3], int ind, int &last, int dp[][4])
{

    if (dp[ind][last] != -1)
    {
        return dp[ind][last];
    }
    if (ind == 0)
    {
        int m = -1;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                m = maximum(m, arr[0][i]);
            }
        }
        return dp[ind][last]=m;
    }

    int ans, final = -1;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            ans = arr[ind][i] + solve(arr, ind - 1, i, dp);
            final = maximum(ans, final);
        }
    }
    return dp[ind][last] = final;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n][3];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
            }
        }
        int dp[n + 1][4];
        memset(dp, -1, sizeof(dp));
        int last = -1;
        cout << solve(arr, n - 1, last, dp) << endl;
    }

// tabulation

    return 0;
}