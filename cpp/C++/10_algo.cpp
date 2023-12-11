#include<iostream>
using namespace std;


int main(){
// sort
int arr[6]={1,3,6,2,5,9};
sort(arr,arr+6);

sort(arr+1,arr+4);// it will sort the second ele to forth ele , not the fifth

vector<int> vec;
sort(vec.begin(),vec.end());
sort(vec.begin()+1,vec.begin()+5);

// reverse
reverse(arr,arr+6);
reverse(vec.begin(),vec.end());
reverse(vec.begin()+1,vec.begin()+5);

// maximum element;
// int max=*max_element(arr,arr+n);// it will give the iterator 
// int max=*max_element(vec.begin(),vec.end());// it will give the iterator 
// int min=*min_element(arr,arr+n);// it will give the iterator 


//
// to find the sum in given range
// int sum=accumulate(arr,arr+n,initial_sum);
int sum=accumulate(arr,arr+n,0);


//to find the occurance of elements
int cnt=count(firstIterator,secondIterator,x);
int cnt=count(vec.begin(),vec.end(),x);

// to find the first occurance of 2;
auto it=find(arr,arr+n,2);//return an iterator
//if the element is not in the array then the iterator will pointing to end.

// if you need the index then you can subtract the iterator with the begin.


//BINARY SEARCH
//only for sorted array
binary_search(firstIterator,secondIterator,ele);
// return true or false
bool res=binary_search(arr,arr+n,10);
bool res=binary_search(vec.begin(),vec.end(),10);


// lower bound
// return an iterator pointing to ele which is not less than x.
// for sorted array
//
auto it = lower_bound(arr,arr+n,x);
// example: arr={1,3,5,7,7,9}// if x is 6 then it will point to first 7 ele.


//upper_bound
auto it = upper_bound(arr,arr+n,x);
// return an iterator pointing to ele which is just greater than x



// next_permutation
// lexographically order of strings

string s="bac";
bool res=next_permutation(s.begin(),s.end());
// it will make the s="cba" and return true to res

// if s="cba" then there is no next permutation then it will return false to res and string will remain same


// lexographical order of strings , print all the permutation of string
  do{
        printf("%s",s);
}while(next_permutation(s.begin(),s.end()));


// prev_permutation
bool res=prev_permutation(s.begin(),s.end());












return 0;
}
