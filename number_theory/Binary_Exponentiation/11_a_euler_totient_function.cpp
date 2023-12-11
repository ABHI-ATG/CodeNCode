#include<bits/stdc++.h>
using namespace std;
/* Atg */
// ROUGH comp - sqrt(n)*logn+np
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)

// to calculate the euler totient function : we will use a formula that is 
// n*(1-1/p)....(1-1/pn);
// some gyaan ki baatein from gfg 

vector<int> unique_prime(int n){
    vector<int> v;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n>2){
        v.push_back(n);
    }
    return v;
}

void solve(){
    int n;
    cin>>n;
    
    vector<int> v=unique_prime(n);

    float res=1;
    for(int i=0;i<v.size();i++){
        res*=(1.0*(v[i]-1))/(1.0*v[i]);
    }
    
    res*=n;
    cout<<(int)res<<" ";
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