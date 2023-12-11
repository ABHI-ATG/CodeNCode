#include <bits/stdc++.h>
using namespace std;
/* Atg */
// this algo find the no of connectes component such that in each component we can traverse each and every node of the component

void topo(vector<vector<int>> &graph,stack<int> &st,int source,vector<int> &vis){
    if(vis[source]){
        return;
    }
    vis[source]=1;
    for(auto it:graph[source]){
        topo(graph,st,it,vis);
    }
    st.push(source);
}

void dfs(vector<vector<int>> graph,vector<int> &vis,int source){
    if(vis[source]){
        return;
    }
    cout<<source<<" ";
    vis[source]=1;
    for(auto it:graph[source]){
        dfs(graph,vis,it);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n+1,0);
    topo(graph,st,1,vis);

    for(int i=0;i<=n;i++){
        vis[i]=0;
    }

    // transpose
    vector<vector<int>> graph_transpose(n+1);
    for(int i=1;i<=n;i++){
        for(auto it:graph[i]){
            graph_transpose[it].push_back(i);
        }
    }

    while(!st.empty()){
        int node=st.top();
        st.pop();
        dfs(graph_transpose,vis,node);
        cout<<endl;
    }


    return 0;
}
