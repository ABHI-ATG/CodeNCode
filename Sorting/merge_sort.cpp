#include <bits/stdc++.h>
using namespace std;

int a[100];

void merge(int l, int m, int r)
{
    int l_s = m - l + 1, r_s = r - m;
    int L[l_s + 1];
    int R[r_s + 1];

    for (int i = 0; i < l_s; i++)
    {
        L[i] = a[i + l];
    }
    for (int i = 0; i < r_s; i++)
    {
        R[i] = a[i + m + 1];
    }
    L[l_s] = INT_MAX;
    R[r_s] = INT_MAX;
    int l_i = 0;
    int r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            a[i] = L[l_i];
            l_i++;
        }
        else
        {
            a[i] = R[r_i];
            r_i++;
        }
    }
}

void mergeSort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}

void print(int r)
{
    for (int i = 0; i < r; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    print(10);
    mergeSort(0, 9);
    print(10);
    return 0;
}