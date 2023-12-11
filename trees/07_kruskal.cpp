#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// kruskal : minimum spanning tree
// mst : a tree whose sum of edges is minimum
// sort all the edges one by one and then make the tree such that no cycle is formed

const int n = 1e3;
vector<pair<int,pair<int,int>>> g;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2,w;
        cin >> v1 >> v2>>w;
        g.push_back({w,{v1,v2}});
    }

    sort(g.begin(),g.end());
    // for(auto it:g){
    //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
    // }
    for (int i = 0; i <=n; i++)
    {
        make(i);
    }
    

    int total_cost=0;
    for(auto &edge:g){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v)){
            continue;
        }
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost;

    return 0;
}