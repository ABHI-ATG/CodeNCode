#include <bits/stdc++.h>
using namespace std;
/* Atg */
// not a good complexity
// comp : (n/2)*log(np)
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

void solve()
{
    int n;
    cin >> n;
    bool arr[n];
    memset(arr, true, n);
    for (int i = 2; i <= n/2; i++)
    {

        if (n % i == 0&&arr[i]!=false)
        {
            for (int j = i; j < n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    int count = 1;
    for (int i = 2; i < n; i++)
    {
        if (arr[i] == true)
        {
            count++;
        }
    }
    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}