#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.
// The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
// You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.
// For Example :
// If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle array will look like:

// 1
// 2,3
// 3,6,7
// 8,9,6,10

// For the given triangle array the minimum sum path would be 1->2->3->8. Hence the answer would be 14.

int minimum(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    
    return 0;
}