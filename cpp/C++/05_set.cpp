#include<iostream>
using namespace std;


int main(){
// set - it will store only the  unique elements
// int arr[]={5,2,2,1,5};
set<int> st;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    st.insert(x);
}
// st - {1,2,5}
// erase functionality
st.erase(st.begin());//it will delete first element => st- {2,5}
st.erase(st.begin(),st.begin()+2);//it will delete first and second ele not the third => st- {5}

// st.erase(key);
st.erase(5);//it will delete 5th index
st.count(2);//counts how many times 2 occurs
set<int> st1={1,2,7,34,54};


auto it=st1.find(7);// it will the iterator which is pointing to 7
auto it=st1.find(43);// it wil give st.end() ( not the last element)

cout<<st.size();
// average time complexity is order of logn

// 
unordered_set<int> st;
st.insert(2);
st.insert(221);
st.insert(223);// it will store element in any order
// average time complexity is order of 1
// the worst case time complexity is linear in nature, order of n

// first preference is unordered set and if you want to store the element in increasing order the use set



// 
// multiset
multiset<int> ms;
ms.insert(1);
ms.insert(1);
ms.insert(2);
ms.insert(2);
ms.insert(3);
// st => {1,1,2,2,3};
// same function

ms.erase(2);//all 2 will be erase;
auto it=ms.find(2);//pointing to first 2



return 0;
}
