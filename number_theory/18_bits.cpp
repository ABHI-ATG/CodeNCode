#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)

void printBinary(int t)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((t >> i) & 1);
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    // print binary
    printBinary(t);

    // bit set
    printBinary(t | 1 << 3);

    // bit unset
    printBinary(t & (~(1 << 2))); //surity
    printBinary(t ^ ((1 << 2)));  // not sure (if previously bit is not set then it will set)

    // toggle
    printBinary(t ^ (1 << 4));
    printBinary(t ^ (1 << 3));

    // even and odd
    if (t & 1)
    {
        cout << "odd\n";
    }
    else
    {
        cout << "even";
    }

    // multiply and divide with bits
    int n = 10;
    n = n >> 1; // n=5
    n = n << 1; // n=10

    // A-a & a-A by bits
    // A - 1000001
    // a - 1100001

    char A = 'A';
    cout << A << " ";
    cout << char(A | (1 << 5));
    cout << char(A | (' ')); // this is better

    char a = 'a';
    cout << char(a & (~(1 << 5)));

    //  (1<<5) is ascii value of  'space'
    cout << char(a & (~(' ')));
    cout << char(a & ('_')); // this is better than upper

    // if i have to unset all bits upto 4 then i can do it with a loop but best choice is written below:
    // 101011 -> 100000
    // 101011 & 110000
    // 110000 = ~(001111) = ~(10000 - 1)

    int m = 43;
    printBinary(m);
    printBinary(m & (~((1 << 4) - 1))); // O(1)

    // check 2's power of two : n&(n-1)
    int k = 16;
    if (k & (k - 1))
    {
        cout << "not two's power";
    }
    else
    {
        cout << "2's power";
    }

    // xor
    // swap
    // a= a^b;
    // b=a^b; //b=a^b^b;
    // a =a^b;//a=a^b&a;
    int a1 = 5;
    int b = 10;
    a1 = a1 ^ b;
    b = a1 ^ b;
    a1 = a1 ^ b;
    cout << a1 << " " << b;

    return 0;
}