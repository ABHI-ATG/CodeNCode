#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)

const int n=1e3;
int parent[n];
int size[n];

void make(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 




return 0;
}