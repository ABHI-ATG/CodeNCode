// Jai Shree Ram
#include <bits/stdc++.h>
using namespace std;

// Atg
#define f(i, _, __) for (ll i = _; i < __; i++)
#define f2(i, __, _) for (ll i = __; i >= _; i--)
#define inf 1000000000000000005
#define india 1000000007
#define INDIA 998244353
#define Welcome ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define array ll n;cin >> n;vector<ll> arr(n);for (auto &it : arr){cin >> it;}
#define out(_) for (auto &it :_){cout << it << " " ;}cout<<endl;
#define str string s;cin >> s;
#define pb push_back
#define vi vector<ll>
#define dbg cout << "Bharat\n";
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define minus cout << "-1\n";
#define endl "\n"
#define ll long long
#define all(v) v.begin(), v.end()
#define mod2 499122177

vector<vector<ll>> mult(vector<vector<ll>> a,vector<vector<ll>> b){
    ll n=a.size();
    ll m=b[0].size();
    vector<vector<ll>> ans(n,vector<ll> (m,0));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll val=0;
            for(ll k=0;k<a[0].size();k++){
                val+=(a[i][k]*b[k][j])%india;
                val%=india;
            }
            ans[i][j]=val;  
        }
    }

    return ans;
}


vector<vector<ll>> power(vector<vector<ll>> v,ll n){
    vector<vector<ll>> a={{1,0},{0,1}};
    while(n){
        if(n&1){
            a=mult(a,v);
        }
        v=mult(v,v);
        n=(n/2);
    }
    return a;
}

void atg()
{
    // array
    // str;
    ll n;
    cin >> n;
    if(n<2){
        cout<<n<<endl;
        return;
    }

    vector<vector<ll>> v(2,vector<ll> (2,1));
    v[0][0]=0;

    vector<vector<ll>> tmp=power(v,n);
    
    n-=2;
    vector<vector<ll>> ans=mult({{1,1}},power(v,n));
    cout<<ans[0][1]<<endl;

    // f(i,0,n){}

    // f(i,0,n){}

    // f(i,0,n){}

    // out(arr);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Welcome;

    ll n = 1;
    // cin >> n;
    while (n--)
    {
        atg();
    }
}
// Atg