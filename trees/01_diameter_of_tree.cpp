#include<bits/stdc++.h>
using namespace std;
/* Abhi-Atg */

int ans;
int dfs(vector<vector<int>> &g, int s, vector<int> &vis){
    vis[s] = 1;
    int cnt=-1;
    for (auto it : g[s]){
        if(vis[it])continue;
        int val=dfs(g, it, vis);
        ans=max(ans,val+cnt+2);
        cnt=max(cnt,val);
    }
    return cnt+1;
}


int main(){

    int n;cin>>n;
    vector<int> vis(n+1,0);
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(g,1,vis);
    cout<<ans;


    return 0;
}