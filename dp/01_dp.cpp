#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

// Dynamic Programming : memoization(top to bottom) and tabulation(bottom to top)
// memoization : store the answer of sub smaller problems;

// fibonacci number

int fib(int n, int dp[])
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // memoiztion : time complexity - O(n) , space complexity - O(n)
    int dp[100];
    memset(dp, -1, sizeof(dp));
    // cout<<fib(5,dp);

    // tabulation : time complexity - O(n) , space complexity - O(n)
    // dp[0] = 0;
    // dp[1] = 1;
    // for (int i = 2; i <= 5; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // cout << dp[5];

    // time complexity - O(n) , space complexity - O(1)
    int prev=0;
    int prev2=1;
    for (int i = 2; i <= 5; i++)
    {
        int ans=prev+prev2;
        prev=prev2;
        prev2=ans;
    }
    cout << prev2;

    return 0;
}