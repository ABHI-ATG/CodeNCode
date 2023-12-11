// gcd
// log(max(a,b)
#include <bits/stdc++.h>
using namespace std;

int gcd(int n,int m){
    return n%m==0?m:gcd(m,n%m);
}

int main()
{   
    int n,m;
    cin>>n>>m;
    cout<<gcd(n,m);
    cout<<__gcd(n,m);
    
    return 0;
}