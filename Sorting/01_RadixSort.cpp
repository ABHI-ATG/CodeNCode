#include <bits/stdc++.h>
using namespace std;
// Radix Sort

void swp(int arr[], int n, int lsb)
{
    int lsb2 = 1;
    for (int i = 0; i < lsb - 1; i++)
    {
        lsb2 = lsb2 * 10;
    }
    vector<vector<int>> v(10);
    for (int i = 0; i < n; i++)
    {
        int orig;
        orig = arr[i] / lsb2;
        int num = orig % 10;
        v[num].push_back(arr[i]);
    }
    int i = 0;

    for (auto it : v)
    {
        for (auto numb : it)
        {
            if(i==n){
                break;
            }
            arr[i++] = numb;
        }
    }
}

void radix(int arr[], int n)
{
    for (int i = 1; i <4; i++)
    {
        swp(arr, n, i);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[10] = {202, 301, 901, 105, 40, 392, 345, 987, 100, 619};
    int n = 10;
    print(arr, n);
    radix(arr, n);
    print(arr, n);
    return 0;
}
