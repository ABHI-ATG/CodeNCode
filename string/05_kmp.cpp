// Jai Shree Ram
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
#define int long long
#define pb push_back
#define endl "\n"
#define all(v) (v.begin(), v.end())

void atg();

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<int> calc_lps(string &pat)
{
    int n = pat.size();
    vector<int> lps(n, 0);
    lps[0] = 0;
    int i = 1;
    int cnt = 0;
    while (i < n)
    {
        if (pat[i] == pat[cnt])
        {
            lps[i++] = ++cnt;
        }
        else
        {
            if (cnt != 0)
            {
                cnt = lps[cnt - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
    }
    // for (auto it : lps)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    return lps;
}

vector<int> kmp(string &text, string &pat)
{
    vector<int> lps = calc_lps(pat);

    int i = 0;
    int cnt = 0;
    vector<int> ans(text.size() + 1, 0);
    while (i < text.size())
    {
        if (text[i] == pat[cnt])
        {
            i++;
            cnt++;
            if (cnt == pat.size())
            {
                ans[i - cnt + 1] = 1;
                cnt = lps[cnt - 1];
            }
        }
        else
        {
            if (cnt != 0)
            {
                cnt = lps[cnt - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return ans;
}

// Atg
int_fast32_t main()
{

    Welcome;
    int n = 1;
    // cin >> n;
    while (n--)
    {
        atg();
    }
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
    char c;
    cin >> c;
    cout<<isupper(c);

    

}
// Atg