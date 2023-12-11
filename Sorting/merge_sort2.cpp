#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int l=mid-low+1,h=high-mid;
    int a1[l], a2[h];
    int i1 = 0, i2 = 0;

    for (int i = low; i < mid + 1; i++)
    {
        a1[i1++] = arr[i];
    }
    for (int i = mid + 1; i <= high; i++)
    {
        a2[i2] = arr[i];
        i2++;
    }
    i1=0;
    int i22 = 0;
    int ind = low;
    while (i1 != l || i22 != h)
    {
        if (a1[i1] < a2[i22])
        {
            arr[ind++] = a1[i1++];
        }
        else
        {
            arr[ind++] = a2[i22++];
        }
    }
    while (i1 != l)
    {
        arr[ind++] = a1[i1++];
    }
    while (i22 != h)
    {
        arr[ind++] = a1[i22++];
    }
}

void merge_sort(int arr[], int low, int high)
{
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 10;
    int arr[10] = {2, 6, 1, 9, 3, 0, 5, 8, 4, 7};
    print(arr, n);
    merge_sort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}