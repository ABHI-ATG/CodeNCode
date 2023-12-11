#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)
// comp - nlogn

// Euler totient function :
// EtF(10)=4 {1,3,7,9}
// gcd of 10 and number from 1 to 9 is 1 

int gcd(int n,int m){
    if(n%m==0){
        return m;
    }
    return gcd(m,n%m);
}

void solve(){
    int n;
    cin>>n;
    int res=1;
    for(int i=1;i<n;i++){
        if(gcd(n,i)==1){
            res++;
            cout<<i<<" ";
        }
    }
    cout<<res<<endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 


    int t;
    cin>>t;
    while(t--){
    solve();
    cout<<endl;
    }


return 0;
}