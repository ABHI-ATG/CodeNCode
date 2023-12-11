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

// Tree flattening :
// convert tree into linear array

/*
    2
   / \
  1   3

  array= [2,1,1,3,3,2];

*/

vector<vector<int>> g(1000005);
int timer = 1;
vector<int> initial(100005);
vector<int> last(100005);
vector<int> tree(200010); // size will be 2*n

void solve(vector<vector<int>> &g, int s, int par)
{
    tree[timer - 1] = s;
    initial[s] = timer++;
    for (auto it : g[s])
    {
        if (it != par)
        {
            solve(g, it, s);
        }
    }
    tree[timer - 1] = s;
    last[s] = timer++;
}

int main()
{

    Welcome;

    return 0;
}