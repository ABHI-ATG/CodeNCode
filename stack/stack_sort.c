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

void sort_stack(int tops){
    if(tops==0){
        return;
    }
    if(stack[tops]<stack[tops-1]){
        int temp=stack[tops];
        stack[tops]=stack[tops-1];
        stack[tops-1]=temp;
        sort_stack(top);
    }
    else{
        sort_stack(tops-1);
    }
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
    sort_stack(top);
    print();
    return 0;
}



