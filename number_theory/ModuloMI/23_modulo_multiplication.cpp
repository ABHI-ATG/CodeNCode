#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)

// MMI
// (a*b)%m==1
//  mmi is defines when a and m are co primes 
// b will be lie in 1 to m-1
// brute force for(1->m-1){ (a*b)%m==1}

// congruency of number, fermet theorem
// a^m-1 == 1modm
//  when a^m-1 divided by m gives remainder 1;
// conditons: m is prime and a is not multiple of m
// a^m-2 == (a^-1)modm
// a^-1=(a^m-2)%m


// NOte: if a and m are not co prime then modulo multiplicative inverse does not exist
int binaryExp(int a,int b,int m){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

int a;
int m;
binaryExp(a,m-2,m);

return 0;
}