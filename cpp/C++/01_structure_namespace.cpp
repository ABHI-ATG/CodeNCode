#include <bits/stdc++.h>// it will include all the header files
using namespace std;// namespace is used to declare the scope, and we can't change the std

// namespace abhi{
//     int val=10;
//     int getval(){
//         return val*10;
//     }
// }

struct node{
int num;
string str;
char a;
double doub;
};
node(num_,str_,a_,doub_){
    num=num_;
    str=str_;
    a=a_;
    doub=doub_;
};

int main(){
    double val=10.01;
    cout<<val<<endl;//print 10.01

    // cout<<abhi::val<<endl;//print 10
    // cout<<abhi::getval()<<endl;


// it is not the good way of storing the data
    // node abhi;
    // abhi.str="abhi";
    // abhi.num=12;
    // abhi.a='a';
    // abhi.doub=12.2;
    node *atg=new node(12,"abhi",'a',12.2);//best way

    return 0;
}

/*  1. namespace
    2. struct and how to store data
*/