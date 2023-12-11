#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)

// binary exponentiation: when value of b is very large 
// a^b^c
// (a%m)^(b%etf(m))%m  , when m is not prime
// (a%m)^(b%(m-1))%m  , when m is prime

const int m=1e9+7;
// m is prime so etf will be (m-1)
const int m1=1337;
// m is not prime , prime factors are 7 and 19 so etf(1337)=1140;
// 
vector<int> primes(int m1){
    vector<int> prime;
    for(int i=2;i*i<=m1;i++){
        if(m1%i==0){
            prime.push_back(i);
            while(m1%i==0){
                m1/=i;
            }
        }
    }
    if(m1>2){
        prime.push_back(m1);
    }
    return prime;
}

int etf(int m1){
    vector<int> prime=primes(m1);
    float ans=1;
    cout<<endl;
    for(int i=0;i<prime.size();i++){
        ans*=(1.0*(prime[i]-1))/(1.0*prime[i]);
    }
    ans*=m1;
    return (int)ans;
}
int binaryExp(int a,int b,int m){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 
    int a=50;
    int b=24;
    int c=32;
    cout<<etf(m1);
    cout<<binaryExp(b,c,etf(m1));
    cout<<binaryExp(a,binaryExp(b,c,etf(m1)),m1);

return 0;
}