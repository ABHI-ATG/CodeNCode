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
void pop(int top){
    --top;
}

    int arr[10000];

int stock(int top,int ele,int i){
    if(top==-1){
        return i;
    }
    if(ele>=stack[top]){
        i++;
    }
    i=stock(top-1,ele,i);
    return i;
}

void stock_span(int top){
    if(top==-1){
        return;
    }
    int i=0;
    int ele=stock(top,stack[top],i);
    arr[top]=ele;
    stock_span(top-1);
}

void print(){
    for(int i=0;i<top+1;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        push(x);
    }
    print();
    stock_span(top);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    // print();
    return 0;
}
