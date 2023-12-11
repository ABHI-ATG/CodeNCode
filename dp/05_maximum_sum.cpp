#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// find the maximum sum of non adjacent element
// input : 1 2 4
// output : 5
// input : 4 1 3 9
// output : 13

void max_non_adjacent(int arr[], int n, int ind, int sum, int &ans, vector<int> v)
{
    if (ind >= n)
    {
        if (ans < sum)
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
            ans = sum;
        }
        return;
    }
    int last;
    if (ind + 2 <= n)
    {
        last = ind + 2;
    }
    else if (ind + 1 <= n)
    {
        last = ind + 1;
    }
    else
    {
        return;
    }
    for (int i = ind; i < last; i++)
    {
        sum += arr[i];
        v.push_back(arr[i]);
        max_non_adjacent(arr, n, i + 2, sum, ans, v);
        max_non_adjacent(arr, n, i + 3, sum, ans, v);
        v.pop_back();
        sum -= arr[i];
    }
}
int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int solve(int arr[], int ind)
{
    if (ind < 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        return arr[0];
    }
    int pick = arr[ind] + solve(arr, ind - 2);
    int notPick = solve(arr, ind - 1);
    int ans = maximum(pick, notPick);
    return ans;
}
int solve2(int arr[], int ind,int dp[])
{
    
    if (ind < 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        return arr[0];
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int pick = arr[ind] + solve(arr, ind - 2);
    int notPick = solve(arr, ind - 1);
    int ans = maximum(pick, notPick);
    return dp[ind]=ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {8, 10, 3, 3, 8, 10, 3, 3};
    int ans = -1;
    vector<int> v;
    // bottom to up
    // max_non_adjacent(arr, 8, 0, 0, ans,v);
    // cout<<ans;

    // top to bottom
    // memoization
    // cout << solve(arr, 7);
    // dp
    int dp[8];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    // cout << solve2(arr, 7,dp);

    // tabulation:
    // 1. dp array
    int dp2[8];
    // 2. base case
    dp2[0]= arr[0];
    int neg=0;
    // bottom to up
    for (int i = 1; i < 8; i++)
    {
        int take=arr[i];
        if(i>1){
            take+=dp2[i-2];
        }
        int nontake=0+dp2[i-1];
        dp2[i]=maximum(take,nontake);
    }
    for(int i=0;i<8;i++){
        cout<<dp2[i]<<" ";
    }


    // space optimisation:
    // int prev=0;
    // int prev2=0;
    // for (int i = 1; i < 8; i++)
    // {
    //     int take=arr[i];
    //     if(i>1){
    //         take+=prev;
    //     }
    //     int nontake=0+prev2;
    //     int curi=maximum(take,nontake);
    //     prev=prev2;
    //     prev2=curi;
    // }
    // cout<<prev2;
    return 0;
}