#include <bits/stdc++.h>
using namespace std;
/* Atg */
// subsequences of string : 
// subsequences sum equal to k

bool solve(int n,int k,vector<int> &arr,vector<vector<int>> &dp){
    if(k==0){
        return true;
    }
    if(n==0){
        return (k==arr[0]);
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }

    int notTake=solve(n-1,k,arr,dp);
    int Take=false;
    if(arr[n]<=k){
        Take=solve(n-1,k-arr[n],arr,dp);
    }
    return dp[n][k]=Take|notTake;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // recursion with dp
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    cout<<solve(n-1,k,arr,dp);

    // memoiation : 
    vector<vector<bool>> dp2(n,vector<bool>(k+1,false));

    for(int i=0;i<n;i++){
        dp2[i][0]=true;
    }
    dp2[0][arr[0]]=true;


    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notTake=dp2[i-1][j];
            bool take=false;
            if(arr[i]<=j){
                take=dp2[i-1][j-arr[i]];
            }
            dp2[i][j]=take|notTake;
        }
    }
    cout<<dp2[n-1][k-1];


    return 0;
}
