// sum of divisor
// sqrt(n);
#include <bits/stdc++.h>
using namespace std;

void sum_divisor(int n){
    int res=1,res_add=1,res_mult=1;
   for(int i=2;i*i<=n;i++){
       res_add=1;
       res_mult=1;
       while(n%i==0){
           res_mult*=i;
           res_add+=res_mult;
           n/=i;
       }
       res*=res_add;
   }
   cout<<res;
}

int main()
{   
    int n;
    cin>>n;
    sum_divisor(n);
    
    return 0;
}