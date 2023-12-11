#include<iostream>
using namespace std;


int main(){
// stack
stack<int> st;
// operations are 
// push pop top  size empty
// push and emplace are the same 

st.push(2);
st.push(3);
st.push(5);
st.push(8);

cout<<st.top();// prints 8
st.pop();// delete 8
cout<<st.top();// prints 5


stack<int> st2;
// stack is empty 
cout<<st.top()<<endl;// it will throw an error 

// for this always have a check
if(!st.empty()){
    cout<<st.top()<<endl;
}



// queue
// 
queue<int> q;
q.push(3);
q.push(7);
q.push(9);

// operations are same of stack









// priority_queue
priority_queue<int> pr_q;
// maximum element at the top 
pr_q.push(1);
pr_q.push(7);
pr_q.push(3);
pr_q.push(9);
// 
pr_q.top();// 9
pr_q.pop();
pr_q.top();// 7

// if i want ascending order of priority_queue
priority_queue<int> pq;
pr.push(-1);
pr.push(-4);
pr.push(-6);
pr.push(-9);

cout<<pr.top*(-1)<<endl;//1

// minimum priority_queue
priority_queue<int,vector<int>,greater<int>> pq;
pq.push(1);
pq.push(4);
pq.push(6);
pq.push(8);
// 
pq.top();// print 1




return 0;
}