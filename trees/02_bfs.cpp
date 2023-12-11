#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// bfs - level
// we can find the shortest path from the source vertex using bfs
// for undirected graph and distance should be equal

const int n = 1e4;
vector<int> g[n];
vector<int> level(n);
bool visited[n];

void bfs(int vertex)
{
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    while (!q.empty())
    {
        int curr_node = q.front();
        cout<<curr_node<<" ";
        q.pop();
        for (int child : g[curr_node])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                level[child] = level[curr_node] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bfs(1);
for(int i=1;i<=v;i++){
    cout<<level[i]<<" "<<i<<endl;
}
    return 0;
}