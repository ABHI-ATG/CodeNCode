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
#define array   \
    int n;      \
    cin >> n;   \
    int arr[n]; \
    f(i, 0, n) { cin >> arr[i]; }
#define string \
    string s;  \
    cin >> s;
typedef long long ll;

void update(vector<int> &v, int ind, int val, int n)
{
    while (ind <= n)
    {
        v[ind] += val;
        ind = ind + (ind & -ind);
    }
}

int getsum(vector<int> &v, int ind)
{
    int sum = 0;
    while (ind > 0)
    {
        sum += v[ind];
        ind = ind - (ind & -ind);
    }
    return sum;
}

int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Welcome;

    int n;
    cin >> n;
    int arr[n+1];
    vector<int> v(n + 1, 0);
    arr[0]=0;
    f(i, 0, n)
    {
        int x;
        cin >> x;
        arr[i+1]=x;
        update(v, i + 1, x, n + 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << getsum(v, r) - getsum(v, l-1) << endl;
        }
        else
        {
            int ind, val;
            cin >> ind >> val;
            val-=arr[ind];
            update(v, ind, val, n + 1);
        }
    }

    return 0;
}