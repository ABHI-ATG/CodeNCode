#include<iostream>
#include <bitset>
using namespace std;


int main(){
// bitset
// bitset - 1 bit
// advantage is in space
// it store either 0 or 1
bitset<4> bt;
cin>>bt;
cout<<bt;

// all
cout<<endl<<bt.all()<<endl;
//if all bits are 1 then it prints 1 otherwise 0

// any
cout<<bt.any()<<endl;
// if any of the bits is 1 then it will print 1 othwise 0

cout<<bt.count()<<endl;
// it will count the 1 only

// flip
bt.flip(2);
// it will flips the bits at 2 index
cout<<bt<<endl;

// 
cout<<bt.none()<<endl;
// it will print 1 if all bits are 0

// set
bt.set();//1111
// it will make all bits 1, as the default value is 1
// bt.set(index,bit value);
bt.set(2,0);// the second index will become 0


// 
bt.reset();//it will convert all bits to 0
// bt.reset(2);

cout<<bt.size();//tell about the size
return 0;
}