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


// 
#include<bits/stdc++.h>
using namespace std;
/* Abhi-Atg */

struct node{
    struct node *l,*r;
    node(){
        l=r=NULL;
    }
};
int ans;
void put(node *ptr,int x,int msb){
    node *head=ptr;
    for(int i=msb;i>=0;i--){
        if(x&(1<<i)){
            if(head->r==NULL){
                head->r= new node();
            }
            head=head->r;
        }else{
            if(head->l==NULL){
                head->l=new node();
            }
            head=head->l;
        }
    }
}
void get(node *ptr,int x,int msb){
    node *head=ptr;
    for(int i=msb;i>=0;i--){
        if(x&(1<<i)){
            if(head->l==NULL){
                head=head->r;
                x=(x^(1<<i));
            }else{
                head=head->l;
            }
        }else{
            if(head->r==NULL){
                head=head->l;
            }else{
                x=(x|(1<<i));
                head=head->r;
            }
        }
    }
    ans=max(ans,x);
}



int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int x=0;
    node *head=new node();
    int msb=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        for(int j=0;j<30;j++){
            if(arr[i]&(1<<j)){
                msb=max(msb,j);
            }
        }
    }
    put(head,0,msb);
    for(int i=0;i<n;i++){
        x=(x^arr[i]);
        get(head,x,msb);
        put(head,x,msb);
    }
    cout<<ans;

    return 0;
}