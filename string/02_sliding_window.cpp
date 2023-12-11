#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)
// sliding window
// time complexity : O(n*m)

bool check(string text,string pattern,int i){
    int ind=0;
    for(int j=i;j<pattern.size()+i;j++){
        if(text[j]!=pattern[ind++]){
            return false;
        }
    }
    return true;
}

int sliding_window(string text,string pattern){
    int cnt=0;
    for(int i=0;i<=text.size()-pattern.size();i++){
        if(check(text,pattern,i)){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    string text;
    cin>>text;
    
    string pattern;
    cin>>pattern;

    cout<<sliding_window(text,pattern);

return 0;
}