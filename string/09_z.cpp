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

void combined_string(string &text, string &patt)
{
    patt.push_back('$');
    for (auto it : text)
    {
        patt.push_back(it);
    }
}

void solve(string &s)
{
    int n = s.size();
    int l = 0, r = 0;
    vector<int> z(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r] == s[r - l])
            {
                r++;
            }
            r--;
            z[i] = r - l + 1;
        }
        else
        {
            if (z[i - l] < r - i + 1)
            {
                z[i] = z[i - l];
            }
            else
            {
                l = i;
                while (r < n && s[r] == s[r - l])
                {
                    r++;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << z[i] << " ";
    }
    cout << endl;
}

int main()
{
    Welcome;

    string patt, text;
    cin >> patt >> text;

    combined_string(text, patt);
    cout << patt << " ";
    cout << endl;

    solve(patt);

    return 0;
}