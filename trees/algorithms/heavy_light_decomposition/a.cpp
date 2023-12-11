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
 
const ll N=200500;
ll val[N],vis[N],height[N];
vector<vector<ll>> g(N);
 
ll nth;
vector<vector<ll>> seg;
vector<ll> num(N);
vector<ll> ind(N);
vector<ll> con(N);
 
class stree{
    vector<ll> v;
public:
    stree(){}
    void re(ll n){
        v.resize(4*n+1);
    }
    ll construct(vector<ll> &arr, ll l, ll r, ll i){
        if (l == r){
            return v[i] = val[arr[l]];
        }
        return v[i]=(construct(arr,l,l+r>>1,2*i+1)+construct(arr,1+(l+r>>1),r,2*i+2));
    }
    ll getvalue(ll low, ll high, ll l, ll r, ll ind){
        if ((l > high) || (r < low)){
            return 0;
        }
        if ((l <= low) && (r >= high)){
            return v[ind];
        }
        return (getvalue(low,low+high>>1,l,r,ind*2+1) + getvalue(1+(low+high>>1),high,l,r,ind*2+2));
    }
    void update(ll low, ll high, ll i, ll val, ll ind){
        if (low == high){
            v[ind] = val;
            return;
        }
        ll mid = (low + high) / 2;
        if (mid >= i)
            update(low, mid, i, val, ind * 2 + 1);
        else
            update(mid + 1, high, i, val, ind * 2 + 2);
        v[ind] = (v[2 * ind + 1] + v[ind * 2 + 2]);
    }
};
 
 
 
ll dfs(ll s){
    if (height[s])return 0;
    height[s] = 1;
    for (auto it : g[s]){
        height[s]=max(height[s],dfs(it)+1);
    }
    return height[s];
}
 
void dfs2(ll s,ll cnt){
    if (vis[s]){
        return;
    }
    vis[s] = 1;
    num[s]=cnt;
    ind[s]=(ll)seg[cnt].size();
    seg[cnt].push_back(s);
 
 
    ll node=0,mx=0;
    for (auto it : g[s]){
        if(vis[it])continue;
        if(mx<height[it]){
            mx=height[it];
            node=it;
        }
    }
 
    if(node){
        for(auto it:g[s]){
            if(vis[it])continue;
            if(it==node){
                dfs2(it,cnt);
            }else{
                seg.pb({});
                con[it]=s;
                dfs2(it,++nth);
            }
        }
    }
 
}
 
void atg()
{
    ll n;cin>>n;
    ll q;cin>>q;
    f(i,1,n+1){
        cin>>val[i];
    }
    f(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(1);
    seg.pb({});
    dfs2(1,0);
 
    // for(ll i=1;i<=n;i++){
    //     cout<<num[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=1;i<=n;i++){
    //     cout<<ind[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=1;i<=n;i++){
    //     cout<<con[i]<<" ";
    // }
    // cout<<endl;
    
    vector<stree> v(nth+1);
    for(ll i=0;i<=nth;i++){
        v[i].re(seg[i].size());
        v[i].construct(seg[i],0,seg[i].size()-1,0);
    }
 
 
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll s,x;
            cin>>s>>x;
            v[num[s]].update(0,seg[num[s]].size()-1,ind[s],x,0);
        }else{
            ll s;
            cin>>s;
            ll ans=0;
            while(s){
                ans+=v[num[s]].getvalue(0,seg[num[s]].size()-1,0,ind[s],0);
                s=con[seg[num[s]][0]];
            }
            cout<<ans<<endl;
        }
    }
 
}
 
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Welcome;
    ll test=1;
    // cin>>test;
    f(i,0,test)
    {
        atg();
    }
}
// Atg