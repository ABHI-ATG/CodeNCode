// position of primes (only)
#include <bits/stdc++.h>
using namespace std;
/* Atg */

// https://codeforces.com/contest/546/problem/D
// https://codeforces.com/contest/222/problem/C
const int n = 100000000;
bool arr[n + 1];
void createseive()
{
    memset(arr, true, n);
    for (int i = 2; i * i < n; i++)
    {
        if (arr[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    int cnt = 0;
    int limit = 5e+6;
    int size;
    for (int i = 2;; i++)
    {
        if (arr[i] == true)
        {
            cnt++;
        }
        if (cnt == limit)
        {
            size = i;
            break;
        }
    }
    cout << cnt << " "
         << " " << size;
    // 86028121
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // seive
    createseive();

    return 0;
}