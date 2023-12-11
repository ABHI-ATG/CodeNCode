#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)


// in this, i have calculated how many number is multiple of a number then the count is subtracted from the n, we get etf;
const int n=1e+5;
int arr[n+1];

void precalculate(){
    memset(arr,0,n);
    f(i,2,n/2+1){
        int num=1;
        if(arr[i]==0){
            for(int j=i+i;j<=n;j+=i){
                arr[j]+=num;
                num++;
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    cout<<n-1-arr[n];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    precalculate();

    int t;
    cin>>t;
    while(t--){
    solve();
    cout<<endl;
    }


return 0;
}