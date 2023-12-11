// factors of a number in best complexity
#include<bits/stdc++.h>
using namespace std;
/* Atg */

const int n=100000;
int arr[n+1];
void createseive(){
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    for(int i=2;i*i<=n;i++){
        if(arr[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(arr[j]==j){
                arr[j]=i;
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    createseive();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        while(n!=1){
            // if(arr[n]==n){
                // cout<<n<<" ";
                // n=n/n;
            // }else{
            cout<<arr[n]<<" ";
            n=n/arr[n];
            // }
        }
        cout<<endl;
    }
    

return 0;
}