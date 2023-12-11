#include <stdio.h>

int arr[10000];
int top=-1;

void push(int c){
    arr[++top]=c;
}

void pop(){
 --top;
}

void balanced_parenthesis(char a[]){
    int i=0;
    int flag=0;
    while(a[i]!='\0'){
        if(a[i]=='('){
            push(1);
        }
        else if(a[i]=='{'){
            push(2);
        }
        else if(a[i]=='['){
            push(3);
        }
        else{
            if(a[i]==')'){
                if(arr[top]==1){
                pop();
                }
                else{
                    flag=1;
                    break;
                }
            }
            else if(a[i]=='}'){
                if(arr[top]==2){
                pop();
                }else{
                    flag=1;
                    break;
                }
            }
            else if(a[i]==']'){
                if(arr[top]==3){
                pop();
                }else{
                    flag=1;
                    break;
                }
            }
        }
        i++;
    }
    if(top!=-1){
        flag=1;
    }
    (flag==1)?printf("NO"):printf("YES");
}

int main()
{
    char a[1000];
    scanf("%s",a);
    balanced_parenthesis(a);
    return 0;
}

