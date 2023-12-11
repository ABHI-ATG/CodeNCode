/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int stack[10000];
int top=-1;
void push(int data){
    stack[++top]=data;
}
void pop(){
    --top;
}
    int res[10000];

void next_greater(int arr[],int n){
    int t=0;
    for(int j=0;j<n;j++){
        if(top==-1){
            push(arr[j]);
        }
        else{
            if(stack[top]>arr[j]){
                push(arr[j]);
            }
            else{
                t=j;
                while((arr[j]>stack[top])&&(top>-1)){
                    res[--t]=arr[j];
                    pop();
                }
                    push(arr[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(res[i]==0){
            res[i]=-1;
        }
    }
    for(int q=0;q<n;q++){
        printf("%d ",res[q]);
    }
}

int main()
{
    int arr[10000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    next_greater(arr,n);

    return 0;
}

