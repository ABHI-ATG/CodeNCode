#include<iostream>
using namespace std;

void insert_at_end(int arr[],int t,int ele){
    arr[t]=ele;
}

void insert_at_beg(int arr[],int n,int ele){
    for(int i=n;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=ele;
}

void insert_at_k(int arr[],int n,int k,int ele){
    for(int i=n-1;i>=k;i--){
        arr[i+1]=arr[i];
    }
    arr[k-1]=ele;
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}

int main(){
int arr[10]={1,2,3,4,5,6};
print(arr,6);
insert_at_end(arr,6,10);
print(arr,7);
insert_at_beg(arr,7,10);
print(arr,8);
insert_at_k(arr,8,3,10);
print(arr,9);
return 0;
}