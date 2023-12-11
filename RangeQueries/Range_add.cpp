#include <bits/stdc++.h>
using namespace std;

// Constant time range add operation on an array 
// using prefix array only;

int main()
{
    int n;
    cin>>n;
    // initially ele of array are 0
    vector<int> v(n+1,0);
    
    int q;
    cin>>q;
    while(q--){
        int l,r,add;
        cin>>l>>r>>add;
        v[l-1]+=add;
        v[r]-=add;
    }
    for(int i=0;i<n-1;i++){
        v[i+1]+=v[i];
    }
    
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    
    /*
    0 0 0 0 0
    //
    1 2 100
    100 100 0 0 0 
    2 5 50
    100 150 50 50 50
    3 4 200
    100 150 250 250 50
    2 3 50
    100 200 300 250 50
    */
    
    
    return 0;
}