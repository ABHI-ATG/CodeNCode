#include <bits/stdc++.h>
using namespace std;
/* Atg */
#define f(i, m, n) for (int i = m; i < n; i++)
#define Welcome                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INDIA 1000000007
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

/*
    matrix multiplicatin :
    if we have Matrix A, we can compute A^x in log(x)*N3;
    https://www.hackerearth.com/practice/notes/matrix-exponentiation-1/
*/



vector<vector<int>> matrix_multiplication(vector<vector<int>> &a, vector<vector<int>> &b, int r1,int c1,int r2,int c2)
{
    vector<vector<int>> res(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < r2; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= INDIA;
            }
        }
    }
    return res;
}

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b, int n)
{
    vector<vector<int>> res(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= INDIA;
            }
        }
    }
    return res;
}

void power(vector<vector<int>> &v, int n, int x)
{
    vector<vector<int>> identity(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        identity[i][i] = 1;
    }

    while (x)
    {
        if (x & 1)
        {
            identity = multiply(identity, v, n);
        }
        v = multiply(v, v, n);
        x /= 2;
    }
    v = identity;
}

int main()
{
    Welcome;

    int n;
    cin >> n;
    vector<vector<int>>
        v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    int x;
    cin >> x;

    power(v, n, x);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}