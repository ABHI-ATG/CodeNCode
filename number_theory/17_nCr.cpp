#include <bits/stdc++.h>
using namespace std;
/* Atg */
// nCr
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

int nCr(int n, int r)
{
    float d;
    if((n-r)>r){
        d=r;
        r=n-r;
    }else{
        d=n-r;
    }

    float res = 1;
    float m = n;
    for (int i = n; i > r; i--)
    {
        res=(float)res*i;
        res /= d;
        d--;
    }
    return (int)res;
}

void solve()
{
    int n;
    cin >> n;
    int r;
    cin >> r;

    cout << nCr(n, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}