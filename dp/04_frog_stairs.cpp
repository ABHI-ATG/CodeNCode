#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {30, 10, 60, 10, 60, 50};
    int dp2[6];
    memset(dp2, 0, sizeof(dp2));
    dp2[0] = 0;
    int k=4;
    int jump;
    for (int i = 1; i <= 5; i++)
    {
        int fs = dp2[i - 1] + abs(arr[i], arr[i - 1]);
        int minstep = INT_MAX;
        for(int j=i;j<=k;j++){
            if(i-j>=0){
                jump=dp2[i-j]+abs(arr[i]-arr[i-j]);
                minstep=minimum(minstep,jump);
            }
        }
        dp2[i] = minstep;
    }
   
    return 0;
}