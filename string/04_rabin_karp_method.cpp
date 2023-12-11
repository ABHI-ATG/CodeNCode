#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// this is very simple approach
// so what can we do we can take a better hash function
// so this better function is given rabin karp method or approach

int check(int text[], int pattern, int t, int p)
{
    int cnt = 0;
    for (int i = p; i < t + 1; i++)
    {
        if (text[i] - text[i - p] == pattern)
        {
            cnt++;
        }
    }
    return cnt;
}

int rabin_karp_function(string text, string pattern)
{
    // first we have to convert in the text and pattern into hash values;
    // formula is simple : (si-'a')*10^i -----> (sn-'a')*10^n;

    int text_value[text.size() + 1];
    int pattern_value = 0;

    // hash function
    text_value[0] = 0;
    for (int i = 1; i < text.size() + 1; i++)
    {
        text_value[i] = ((int)(text[i - 1] - 'a') + 1) * (int)pow(10, i - 1);
    }

    for (int i = 1; i < text.size() + 1; i++)
    {
        text_value[i] += text_value[i - 1];
    }

    for (int i = 0; i < pattern.size(); i++)
    {
        pattern_value += ((int)(pattern[i] - 'a') + 1) * (int)pow(10, i);
    }
    for (int i = 0; i < text.size(); i++)
    {
        cout<<text_value[i]<<" ";
    }
    cout<<pattern_value<<" ";

    //
    return check(text_value, pattern_value, text.size(), pattern.size());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text;
    string pattern;
    cin >> text >> pattern;

    cout << rabin_karp_function(text, pattern);

    return 0;
}