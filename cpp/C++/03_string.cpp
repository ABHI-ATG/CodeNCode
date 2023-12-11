#include<bits/stdc++.h>
using namespace std;


int main(){
// iterators
// begin()- it is first element
// rbegin()- it will point to last element
// end()- it will point to right after the last element(not the last element)
// rend()- it will point to right before the first element(not the last element)

array<int,5> arr;
arr.fill(10);
arr.at(4)=5;
// it is not the best way to iterate the array
// for(int i=0;i<5;i++){
// cout<<arr.at(i);
// }

// for(auto it=arr.begin();it!=arr.end();it++){
//     cout<<it<<" "; 
// }

// it is like foreach loop
for(auto it:arr){   
    cout<<it<<" ";
}

// string 

string s="abhi";
for(auto c:s){// it wil go one by one to characters
    cout<<c<<" ";
}

//
cout<<arr.size();
cout<<arr.front();// it is arr.at(0)
cout<<arr.back();// it is arr.at(arr.size()-1)



return 0;
}