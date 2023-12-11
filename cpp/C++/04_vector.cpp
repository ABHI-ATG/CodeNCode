#include<iostream>
using namespace std;


int arr2[10000000];//it is the maximum size of 10^7 declared globally

int main(){
int ar[1000000];// maximum size of 10^6 inside int main()
bool arr3[1000000];//maximum size of 10^7 of boolean type array inside int main()

// VECTOR
vector<int> arr;// {} -- it will declare array dynamically (an empty array is created)
arr.push_back(0);  //{0}  
arr.push_back(2);  //{0,2}  
cout<<arr.size()<<endl;

arr.pop_back();  // it will pop out last element from the array 


// SEGMENTATION FAULT
// when we allocate more than usual memory in data types

vec.clear();// it will erase all elements at once;

vector<int> vec1(4,0); // {0,0,0,0}
vector<int> vec2(4,10); // {10,10,10,10}

vector<int> vec3(vec2.begin(),vec2.end());  // {10,10,10,10}
vector<int> vec3(vec2);  // same as above



vector<int> vec4; 
vec4.push_back(1);
vec4.push_back(2);
vec4.push_back(3);
vec4.push_back(4);
                                              // {1,2,3,4}
vector<int> vec5(vec4.begin(),vec4.begin()+2);// {1,2}

// lower bound

// upper bound

// swap swap(v1,v2)



// 2-D vectors
vector<vector<int>> vec;
vector<int> ptr;
ptr.push_back(1);
ptr.push_back(2);

vector<int> ptr2;
ptr2.push_back(1);
ptr2.push_back(2);

vec.push_back(ptr1);
vec.push_back(ptr2);

for(auto vctr:vec){
    for(auto it:vctr){
       cout<<it<<" ";
    }
    cout<<endl;
}
// define 10*20 dynamically
vector<vector<int>> vec(10,vector<int> vec(20,0));// 10 rows and each row will have 20 size array

// array of vectors
vector<int> arr[4];
// the above code is not meant int arr[4];, every index of arr is vector itself



// define 10X20X30
vector<vector<vector









return 0;
}