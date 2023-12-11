#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)
const int N=1e5;
vector<pair<int,int>> g[N];

void dijkstra(int source){
    vector<int> visited(N,0);
    vector<int> dis(N,INT_MAX);

    set<pair<int,int>> st;

    st.insert({0,source});
    // visited[source]=1;
    dis[source]=0;

    while(st.size()>0){
        auto node=*st.begin();
        int v=node.second;
        int w=node.first;
        st.erase(st.begin());
        if(visited[v]){
            continue;
        }
        visited[v]=1;
        for(auto child:g[v]){
            int child_v=child.first;
            int child_wt=child.second;
            if(dis[v]+child_wt<dis[child_v]){
                dis[child_v]=dis[v]+child_wt;
                st.insert({dis[child_v],child_v});
            }
        }
    }
    for(int i=1;i<7;i++){
        cout<<dis[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        // for directed edge
        g[x].push_back({y,w});
    }
    dijkstra(1);
    cout<<"hello2";
return 0;
}