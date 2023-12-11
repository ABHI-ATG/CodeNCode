#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)
// a^b%m
// when a is 10^18 then we can easily find by (a%m)^b%m

// but when m is large that is 10^18
// then multiply of a*a will be of more than 10^18 which is not possible
// so we will multiply by binary addition 

const long long int m = 1e18+7;

ll binaryMult(ll a,ll b){
    ll ans=0;
    while(b){
        if(b&1){
            ans+=a;
            ans%=m;
        }
        a+=a%m;
        b>>=1;
    }
    return ans;
}

ll binaryExp(ll a,ll b){
    if(b==1){
        return a;
    }
    if(b&1){
        ll ans=binaryExp(a,b/2);
        return (binaryMult(ans,ans)*a)%m;
    }else{
        ll ans=binaryExp(a,b/2);
        return binaryMult(ans,ans)%m;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    ll a=2;
    ll b=16;
    cout<<binaryExp(a,b);

return 0;
}