#include<bits/stdc++.h>
using namespace std;
/* Atg */
// sqrt(n)

void solve(){
    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            cout<<n/i<<" ";
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    // #ifdef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    // #endif
    int t;
    cin>>t;
    while(t--){
    solve();
    cout<<endl;
    }


return 0;
}