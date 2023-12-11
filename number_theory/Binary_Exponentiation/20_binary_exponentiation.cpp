#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)

int power(int a,int b){
    if(b==1){
        return a;
    }
    if(b&1){
        int ans=power(a,b/2);
        return ans*ans*a;
    }else{
        int ans=power(a,b/2);
        return ans*ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

// o(n)
    int a=2;
    int b=13;
    int res=1;
    for(int i=0;i<b;i++){
        res*=a;
    }

// recursive formula
// log(n)
// b-even, f(a,b)=f(a,b/2)*f(a,b/2);
// b-odd, f(a,b)=a*f(a,b/2)*f(a,b/2);

    cout<<power(a,b)<<endl;;


// iterative method 
// log(n)
int ans=1;
while(b){
    if(b&1){
        ans=ans*a;
    }
    a=a*a;
    b=b>>1;
}
cout<<ans;
return 0;
}