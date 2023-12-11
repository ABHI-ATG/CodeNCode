/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

char arr[10000];
int top=-1;
void push(char data){
    arr[++top]=data;
}
char pop(){
    return arr[top--];
}

void infix_postfix(char c[]){
    int i=0;
    char res[1000];
    int j=0;
    int flag=0;
    while(c[i]!='\0'){
        if(c[i]=='+'){
            if(flag==0){
            if(arr[top]=='*'||arr[top]=='/'){
                while(arr[top]=='*'||arr[top]=='/'){
                    res[j++]=pop();
                }
            }
            }
            push('+');
        }
        else if(c[i]=='-'){
            if(flag==0){
            if(arr[top]=='*'||arr[top]=='/'){
                while(arr[top]=='*'||arr[top]=='/'){
                    res[j++]=pop();
                }
            }
            }
            push('-');
        }
        else if(c[i]=='*'){
            if(arr[top]=='/'){
                res[j++]=pop();
            }
            push('*');
        }
        else if(c[i]=='/'){
            if(arr[top]=='*'){
                res[j++]=pop();
            }
            push('/');
        }
        else if(c[i]=='('){
            push('(');
            flag=1;
        }
        else if(c[i]==')'){
            while(arr[top]!='('){
                res[j++]=pop();
            }
            flag=0;
            pop();
        }
        else{
            res[j++]=c[i];
        }
        i++;
    }
    while(top!=-1){
        res[j++]=pop();
    }
    for(int a=0;a<j;a++){
        printf("%c",res[a]);
    }
}

int main()
{
    char c[1000];
    scanf("%s",c);
    infix_postfix(c);

    return 0;
}

