#include<iostream>
using namespace std;


int main(){
int arr[]={1,3,6,2,7,5,9};
sort(arr,arr+n);//sort in ascending order
// sort(arr,arr+n,comp);// to sort in descending, we use comparator

bool comp(int ele1,int ele2){
    if(ele1<=ele2){
return true;
    }
    return false;
}

sort(arr,arr+n,greater<int>);

return 0;
}