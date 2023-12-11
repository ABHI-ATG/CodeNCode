/*
n=4

Valid:
    (())
    ()()
Invalid:                After flipping each bracket after first invalid position
k open and k close          k-1 open and k+1 close
    ())(                    ())(
    )(()                    )))(
    )()(                    ))()
    ))((                    )()


2kCk - good + bad bracket
good = 2kCk - bad
good = 2kCk - 2kCk-1
good = catalan number



Find Ck/Ck-1

Ck = (4*k-2)* Ck-1 / (k+1)       relation between Ck and Ck-1 where Co =1 

    

*/









#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// catalan number;
// Cn = C0Cn-1+C1Cn-2+...+cn-1c0
// 1,1,2,5,14,42,132
// 
// properties
// no of bst
// bst with labelled node is - Cn*n!
// parenthesis Cn
// Dyck Words : XY XXYY XYXY - Cn
// Mountain Range : Number of Mountain Peak above x axis - Cn
// Path on grid : Reaching from bottom left to top right - Cn
// Convex Polygon : number of traingle can be formed with given edges - Cn
// Chords in circle : Cn or Cn/2


// catalan number :  2nCn/(n+1);
    void solve()
{
    int n;
    cin >> n;
    float ans=1;
    int m=n;
    int temp=0;
    for (int i = 2*n; i >n; i--)
    {
        ans*=i;
        ans/=m;
        m--;
    }
    cout<<(int)ans/(n+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}