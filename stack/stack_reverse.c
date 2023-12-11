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

void push_bottom(int ele){
    if(top==-1){
        stack[++top]=ele;
        return;
    }
    int element=stack[top];
    pop();
    push_bottom(ele);
    push(element);
}

void reverse_stack(int top){
    
    if(top==-1){
        return;
    }
    int ele=stack[top];
    pop();
    reverse_stack(top-1);
    push_bottom(ele);
}

void print(){
    for(int i=0;i<top+1;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10000];
    int n;
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        push(x);
    }
    print();
    reverse_stack(top);
    print();
    return 0;
}



