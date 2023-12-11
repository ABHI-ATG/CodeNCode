#include<iostream>
using namespace std;

int binary_search(int arr[],int low,int high,int ele){
    if(high>=low){
    int mid=(low+high)/2;
    if(arr[mid]==ele){
        return mid;
    }
    else if(ele<arr[mid]){
        return binary_search(arr,low,mid-1,ele);
    }
    else if(ele>arr[mid]){
        return binary_search(arr,mid+1,high,ele);
    }
    }
    if(arr[high]>ele){
        return low;
    }else{
    return high;
    }
}

void binary_insert(int arr[],int ele,int n){
int low=0;
int high=n;
int num=binary_search(arr,low,high,ele);
// cout<<num;
for(int i=high;i>num;i--){
    arr[i]=arr[i-1];
}
arr[num]=ele;
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}

int main(){
int arr[10]={1,2,3,5,6};
print(arr,5);
binary_insert(arr,4,5);
print(arr,6);
binary_insert(arr,8,6);
print(arr,7);
binary_insert(arr,3,7);
print(arr,8);

return 0;
}