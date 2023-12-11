// 2 is only prime numnber
// prime number can be written as 6b+1 or 6n-1 except 2 or 3
// goldbach conjective : every even integer greater than 2 can be written as sum of two primes
// wilson theorem : (p-1)!modp = (p-1)modp
// 2 and 3 are only two consecutive number that are prime


// prime : have two significant factor only
// check for prime
// sqrt(n);
#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool ans=true;
    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans=false;
            break;
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
     cout<<"NO"<<endl;   
    }
    return 0;
}