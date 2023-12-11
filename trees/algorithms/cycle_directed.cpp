#include<bits/stdc++.h>
using namespace std;
/* Abhi-Atg */
const int N=100500;
int n;
int m;
vector<int> vis(N,0);
vector<int> mark(N,0);
vector<int> v;
vector<vector<int>> g(N);

int dfs(int s){
    if(mark[s]){
        v.push_back(s);
        return 1;
    }
    if (vis[s]){
        return 0;
    }
    vis[s] = 1;
    mark[s]=1;
    v.push_back(s);
    for (auto it : g[s]){
        if(dfs(it)){
            return 1;
        }
    }
    mark[s]=0;
    v.pop_back();
    return 0;
}

int main(){

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    int flag=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] && dfs(i)){
            flag=1;
            break;
        }
    }

    if(!flag){
        cout<<"IMPOSSIBLE\n";
        goto out;
    }


    reverse(v.begin(),v.end());
    while(v.back()!=v[0]){
        v.pop_back();
    }
    reverse(v.begin(),v.end());
    cout<<(int)v.size()<<endl;
    for(auto it:v)cout<<it<<" ";

    out:


    return 0;
}