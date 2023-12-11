// all primes of a number
// O(sqrt(n)*log n)
#include <bits/stdc++.h>
using namespace std;

void all_primes(int n){
    while(n%2==0){
        cout<<2<<" ";
        n/=2;
    }
    int i=3;
    while(1){
        if(n<2||i*i>n){
            break;
        }
        if(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }else{
            i+=2;
        }
    }
    if(n>2){
        cout<<n;
    }
}

int main()
{   
    int n;
    cin>>n;
    all_primes(n);
    
    return 0;
}