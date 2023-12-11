#include <bits/stdc++.h>
using namespace std;
/* Atg */
typedef long long int ll;
#define f(i, m, n) for (int i = m; i < n; i++)
// identification
// Kth number and smallest or largest number
// for smallest - max heap
// for largest - min heap

// complexity is nlogn
// nlogn - nlogk

// heap - priority queue
const int n = 1e3;
int heap[n];
int size = 0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int n = 0) // minHeap
{
    int smallest = n;
    int left = 2 * n + 1;
    int right = 2 * n + 2;
    if (heap[n] > heap[left] && left <= size)
    {
        smallest = left;
    }
    if (heap[n] > heap[right] && right <= size)
    {
        smallest = right;
    }
    if (smallest != n)
    {
        swap(heap[smallest], heap[n]);
        heapify(heap[smallest]);
    }
}

void makeHeap()
{
    int x;
    cin >> x;
    heap[size++] = x;
    heapify();
}

int getMin()
{
    if (size != 0)
    {
        return heap[0];
    }
}

void extractMin()
{
    if (size == 0)
    {
        cout << "Heap is empty\n";
        return;
    }
    else if (size == 1)
    {
        size--;
        return;
    }
    heap[0] = heap[--size];
    for (int i = 0; i < size; i++)
    {
        heapify();
    }
}



void make(int i){

    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<=size||r<=size){
        make(l);
        make(r);
        if(l<=size&&heap[largest]<heap[l]){
            largest=l;
        }
        if(r<=size&&heap[largest]<heap[r]){
            largest=r;
        }
        if(largest!=i){
        swap(heap[largest],heap[i]);
        }
    }
}

void deleteKey(){
    int i;
    cin>>i;
    heap[i]=INT_MAX;
    for(int i=0;i<size;i++){
        heapify(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    makeHeap();
    makeHeap();
    makeHeap();
    makeHeap();
    makeHeap();

    cout << getMin(); // return root

    extractMin();

    deleteKey(); 

    return 0;
}