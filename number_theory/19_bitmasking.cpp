#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

//  we store the number as bit in place to store them in array 
// condition is that the number n must be small
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

int t;
cin>>t;
vector<int> mask(t,0);
int i=0;
int k=t;
while(t--){
    int worker;
    cin>>worker;
    while(worker--){
        int days;
        cin>>days;
        mask[i]=mask[i]|(1<<days);
    }
    i++;
}
int max=-1,res=-1;
int num=0;
int person1=-1,person2=-1;
for(int i=0;i<k;i++){
    for(int j=i+1;j<k;j++){
        int intersection=mask[i]&mask[j];
        max=__builtin_popcount(intersection);
        num=j;
    }
    if(res<max){
        person1=i;
        person2=num;
        res=max;
    }
}

cout<<res<<" "<<person1<<" "<<person2;
return 0;
}