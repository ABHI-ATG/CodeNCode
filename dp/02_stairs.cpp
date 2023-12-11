#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)
// stairs : rules: we can climb one or two stair at a time 
// find different ways to climb the stairs;

void stairs(int n,int &ans){
    if(n<0){
        return;
    }
    if(n==0){
        ans++;
        return;
    }
    stairs(n-1,ans);
    
    stairs(n-2,ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n=10;
    int ans=0;
    stairs(n,ans);
    cout<<ans;

return 0;
}