#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// frog is at index 0, we have to calculate the minimum cost to reach the last index or stair, rules: the frog can jump one or two stairs ,the minimum cost is given below;
// 10 20 50 30
// 20

int abs(int a, int b)
{
    if (a > b)
    {
        return a - b;
    }
    return b - a;
}

int minimum(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int frog(int arr[], int ind, int dp[])
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int left = abs(frog(arr, ind - 1, dp), arr[ind]);
    int right = INT_MAX;
    if (ind - 2 >= 0)
    {
        right = abs(frog(arr, ind - 2, dp), arr[ind]);
    }
    return dp[ind] = minimum(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int arr[] = {30, 10, 60, 10, 60, 50};
    int min = INT_MAX;
    int dp[6];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    // cout << frog(arr, 5, dp);

    // tabualtion :
    int dp2[6];
    memset(dp2, 0, sizeof(dp2));
    dp2[0] = 0;
    for (int i = 1; i <= 5; i++)
    {
        int fs = dp2[i - 1] + abs(arr[i], arr[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
        {
            ss = dp2[i - 2] + abs(arr[i], arr[i - 2]);
        }
        dp2[i]=minimum(fs,ss);
    }
    for (int i = 0; i < 6; i++)
    {
        cout<<dp2[i]<<" ";
    }

    // space complexity : O(1)
    int prev=0,prev2=0;
    for (int i = 1; i <= 5; i++)
    {
        int fs = prev+ abs(arr[i], arr[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
        {
            ss = prev2 + abs(arr[i], arr[i - 2]);
        }
        prev2=prev;
        prev=minimum(fs,ss);
    }
    cout<<prev;
    return 0;
}