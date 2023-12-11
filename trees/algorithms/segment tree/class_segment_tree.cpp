#include <bits/stdc++.h>

using namespace std;

// Atg

#define f(i, m, n) for (int i = m; i < n; i++)
#define f2(i, n, m) for (int i = n; i >= m; i--)
#define Welcome                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INDIA 1000000007
#define number \
    int n;     \
    cin >> n;
#define array   \
    int n;      \
    cin >> n;   \
    int arr[n]; \
    f(i, 0, n) { cin >> arr[i]; }
#define array2  \
    int n;      \
    cin >> n;   \
    int x;      \
    cin >> x;   \
    int arr[n]; \
    f(i, 0, n) { cin >> arr[i]; }
#define str   \
    string s; \
    cin >> s;
#define debug cout << "Bharat\n";
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define minus cout << "-1\n";
#define print                             \
    f(i, 0, n) { cout << arr[i] << " "; } \
    cout << endl;
#define pb push_back
#define endl "\n"
typedef long long ll;

void atg();

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int abs(int a, int b)
{
    if (a > b)
    {
        return a - b;
    }
    return b - a;
}

int mod(int n)
{
    if (n < 0)
    {
        return -1 * n;
    }
    return n;
}

int converse(int n)
{
    return -1 * n;
}

// Atg

class SGT
{
    vector<int> seg;

public:
    SGT(int n)
    {
        seg.resize(4 * n + 1);
    }

    int construct(int arr[], int l, int r, int i)
    {
        if (l == r)
        {
            seg[i] = arr[l];
            return arr[l];
        }

        // range
        int mid = (l + r) / 2;

        int left = construct(arr, l, mid, 2 * i + 1);
        int right = construct(arr, mid + 1, r, 2 * i + 2);
        return seg[i] = min(left, right);
    }

    int getvalue(int low, int high, int l, int r, int ind)
    {
        //  no overlap
        if ((l > high) || (r < low))
        {
            return INT_MAX;
        }
        // complete overlap
        if ((l <= low) && (r >= high))
        {
            return seg[ind];
        }
        // partial overlap
        int mid = (low + high) / 2;
        int left = getvalue(low, mid, l, r, ind * 2 + 1);
        int right = getvalue(mid + 1, high, l, r, ind * 2 + 2);
        return min(left, right);
    }

    void update(int low, int high, int i, int val, int ind)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;

        if (mid >= i)
        {
            update(low, mid, i, val, ind * 2 + 1);
        }
        else
        {
            update(mid + 1, high, i, val, ind * 2 + 2);
        }
        seg[ind] = min(seg[2 * ind + 1], seg[ind * 2 + 2]);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Welcome

        number while (n--)
    {
        atg();
    }
    return 0;
}

/*



        *         *  *  *  *  *         *  *  *
      *   *             *             *
    *       *           *            *      *  *  *
  *  *  *  *  *         *             *          *
*              *        *                *  *  *




*/

void atg()
{

    // number;
    array;

    //  segment size will be 4*n
    SGT sg1(n);
    sg1.construct(arr, 0, n - 1, 0);
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
            cout << sg1.getvalue(0, n - 1, l, r, 0) << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            sg1.update(0, n - 1, i, val, 0);
        }
    }
    // str;
    // f(i,0,n){

    // }
}

// Atg
