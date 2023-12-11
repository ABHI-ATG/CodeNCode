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

vector<int> manacher(string s)
{

    int n = s.size();
    string t;
    t.push_back('#');
    for (int i = 0; i < n; i++)
    {
        t.push_back(s[i]);
        t.push_back('#');
    }
    //

    n = n * 2 + 1;
    vector<int> v(n, 0);

    int start = 1, ind = 1;

    while (start < n)
    {
        if (start - ind >= 0 && start + ind < n && t[start + ind] == t[start - ind])
        {
            ind++;
        }
        else
        {
            if (ind == 1)
            {
                start++;
            }
            else
            {
                int l = start - ind + 1;
                int r = start + ind - 1;
                v[start] = ind - 1;
                int tmp = 0;
                for (int i = start - 1; i >= l; i--)
                {
                    int opp = 2 * start - i;
                    if (i - v[i] == l)
                    {
                        start = opp;
                        ind = v[i] + 1;
                        tmp = 1;
                        break;
                    }
                    else
                    {
                        v[opp] = min(v[i], i - l);
                    }
                }
                if (tmp == 0)
                {
                    ind = 1;
                    start = r + 1;
                }
            }
        }
    }

    int index = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
        if (mx < v[i])
        {
            mx = v[i];
            index = i;
        }
    }

    return v;
}

int main()
{

    Welcome;

    str;

    manacher(s);

    return 0;
}