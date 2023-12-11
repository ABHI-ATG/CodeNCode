// Eulerian Path is a path in a graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path that starts and ends on the same vertex. 

// “Is it possible to draw a given graph without lifting pencil from the paper and without tracing any of the edges more than once”.
// A graph is called Eulerian if it has an Eulerian Cycle and called Semi-Eulerian if it has an Eulerian Path

#include<bits/stdc++.h>
using namespace std;
/* Abhi-Atg */
#define ll long long


int main(){


    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    // cin >> t;
    while(t--){

        int n,m;cin >> n >> m;
        vector<set<int>> g(n+1);
        for(int i=0;i<m;i++){
            int a,b;cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }

        int node=-1;
        for(int i=1;i<=n;i++){
            if(g[i].size()){
                node=i;
                break;
            }
        }

        // graph has no edge
        if(node==-1){
            cout<<"YES\n";
            return 0;
        }

        int odd=0;
        int tot=0;
        for(int i=1;i<=n;i++){
            if(g[i].size()&1){
                odd++;
                node=i;
            }
            tot+=(g[i].size()>0);
        }


        int cnt=0;
        vector<int> vis(n+1);
        function<void(int)> dfs=[&](int s){
            vis[s]=1;
            cnt++;
            for(auto it:g[s]){
                if(vis[it])continue;
                dfs(it);
            }
        };
        dfs(node); // to check graph is connected or not


        // 
        if((odd==2 || odd==0) && cnt==tot){
            stack<int> s;
            s.push(node);
            vector<int> ans;
            while(!s.empty()){
                int u=s.top();
                if(g[u].size()){
                    int e=*--g[u].end();
                    s.push(e);
                    g[u].erase(e);
                    g[e].erase(u);
                }else{
                    ans.push_back(u);
                    s.pop();
                }
            }

            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"IMPOSSIBLE";
        }

    }


    return 0;
}