#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partitioning(int arr[],int l,int h){
    int pivot=arr[l];
    int start=l;
    int end=h;
    while(start<end){
        while(pivot>=arr[start]){
            start++;
        }
        while(pivot<arr[end]){
            end--;
        }
        if(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    
    int temp=arr[end];
    arr[end]=pivot;
    arr[l]=temp;
    return end; // key point
}

void quick_sort(int arr[],int l,int h){
    if(l<h){
        int loc=partitioning(arr,l,h);
        quick_sort(arr,l,loc-1);
        quick_sort(arr,loc+1,h);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    int arr[10]={5,9,1,4,7,2,8,3,0,6};
    print(arr,10);
    quick_sort(arr,0,9);
    print(arr,10);

return 0;
}