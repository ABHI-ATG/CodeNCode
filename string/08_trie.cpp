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

struct Node
{
    Node *arr[26];
    bool flag = false;
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string s)
    {
        int n = s.size();
        Node *ptr = root;
        for (int i = 0; i < n; i++)
        {
            if (ptr->arr[s[i] - 'a'] == 0)
            {
                ptr->arr[s[i] - 'a'] = new Node();
            }
            ptr = ptr->arr[s[i] - 'a'];
        }
        ptr->flag = true;
    }

    bool search(string s)
    {
        int n = s.size();
        Node *ptr = root;

        for (int i = 0; i < n; i++)
        {
            if (ptr->arr[s[i] - 'a'] == 0)
            {
                return false;
            }
            ptr = ptr->arr[s[i] - 'a'];
        }
        return ptr->flag;
    }
};

int main()
{

    Welcome;

    Trie v;
    v.insert("abhi");
    v.insert("abh");
    v.insert("a");

    return 0;
}