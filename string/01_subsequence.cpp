// subsequence
#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m=pow(2,n);
    f(i,1,m){
        f(j,0,n){
            int temp=1<<j;
            if(i&temp){
                cout<<s[j]<<" ";
            }
        }
        cout<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
    solve();
    cout<<endl;
    }


return 0;
}