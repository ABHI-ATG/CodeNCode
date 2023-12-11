#include <bits/stdc++.h>
using namespace std;
/* Atg */
#define f(i, m, n) for (int i = m; i < n; i++)
#define Welcome                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define number \
    int n;     \
    cin >> n;
#define array          \
    int n;             \
    cin >> n;          \
    int arr[n];        \
    f(i, 0, n)         \
    {                  \
        cin >> arr[i]; \
    }
#define str   \
    string s; \
    cin >> s;
typedef long long ll;

// for finding topological sort of directed acyclic graph

vector<int> kahn(vector<vector<int>> g,int n){

    // remember that graph is directed and acyclic

    vector<int> in_degree(n+1,0);

    // finding in_degree of each node
    for(auto it:g){
        for(auto itt:it){
            in_degree[itt]++;
        }
    }

    // adding those node whose in_degree is zero;
    vector<int> q;
    for(int i=1;i<n+1;i++){
        if(in_degree[i]==0){
            q.push_back(i);
        }
    }

    // just decrementing value of in_degree of each adjacent nodes of a node and if the in_degree is 0 then add it queue; 
    for(int i=0;i<q.size();i++){
        for(auto it:g[q[i]]){
            in_degree[it]--;
            if(in_degree[it]==0){
                q.push_back(it);
            }
        }
    }

    return q;
}

int main()
{

    Welcome;

    return 0;
}