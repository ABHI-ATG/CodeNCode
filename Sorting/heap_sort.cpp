#include<bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i,m,n) for(int i=m; i<n; i++)

void heapify(int arr[],int n,int l1){
    int largest=l1;
    int l=2*l1+1;
    int r=2*l1+2;
    while(l<=n&&arr[largest]<arr[l]){
        largest=l;
    }
    while(r<=n&&arr[largest]<arr[r]){
        largest=r;
    }
    if(largest!=l1){
        int temp=arr[largest];
        arr[largest]=arr[l1];
        arr[l1]=temp;
        heapify(arr,n,largest);
    }
}

void max_heapify(int arr[],int n){
    if(n==0){
        return ;
    }
    {int temp=arr[0];
    arr[0]=arr[n];
    arr[n]=temp;}
    heapify(arr,n-1,0);
    max_heapify(arr,n-1);
}

void make_heap(int arr[],int n,int i){

    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<=n||r<=n){
        make_heap(arr,n,l);
        make_heap(arr,n,r);
        if(l<=n&&arr[largest]<arr[l]){
            largest=l;
        }
        if(r<=n&&arr[largest]<arr[r]){
            largest=r;
        }
        if(largest!=i){
        swap(arr[largest],arr[i]);
        }
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    int arr[10]={5,8,2,9,1,7,3,0,4,6};
    print(arr,10);
    for(int i=0;i<5;i++){
    make_heap(arr,9,0);
    }
    print(arr,10);
    max_heapify(arr,9);
    print(arr,10);

return 0;
}