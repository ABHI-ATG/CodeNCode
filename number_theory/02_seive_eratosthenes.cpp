#include<bits/stdc++.h>
using namespace std;
/* Atg */


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n=1e+5;
    bool arr[n];
    memset(arr,true,n);
    // more opti is i*i<=n
    for(int i=2;i*i<=n;i++){
        if(arr[i]==true){
            // int j=i+i;
            // more optimisation is 
            // int j=i*i;
            for(int j=i*i;j<n;j+=i){
                arr[j]=false;
            }
        }
    }

    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        for(int i=2;i<m;i++){
            if(arr[i]==true){
                cout<<i<<" ";
            }
        }
    cout<<endl;
    }
return 0;
}