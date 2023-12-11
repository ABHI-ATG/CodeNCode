#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)
//  rolling hash function
//  simple hash function
//  too many collisions
// not a good approach


int check(int text[],int pattern,int t,int p){
    int cnt=0;
    for(int i=p;i<t+1;i++){
        if(pattern==text[i]-text[i-p]){
            cnt++;
        }
    }
    return cnt;
}

int rolling_hash_function(string text,string pattern){
    // for small letters
    int pattern_value=0;
    int text_value[text.size()+1];
    
    // text hash
    text_value[0]=0;
    for(int i=1;i<text.size()+1;i++){
        text_value[i]=(int)(text[i-1]-'a')+1;
    }
    for(int i=1;i<text.size()+1;i++){
        text_value[i]+=text_value[i-1];
    }

    // pattern hash value
    for(int i=0;i<pattern.size();i++){
        pattern_value+=(int)(pattern[i]-'a')+1;
    }

    for(int i=0;i<text.size()+1;i++){
        cout<<text_value[i]<<" ";
    }
    cout<<pattern_value<<" ";

    return check(text_value,pattern_value,text.size(),pattern.size());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    string text;
    string pattern;
    cin>>text>>pattern;

    cout<<rolling_hash_function(text,pattern);

return 0;
}