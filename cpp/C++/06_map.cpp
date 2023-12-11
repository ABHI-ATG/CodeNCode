#include<iostream>
using namespace std;


int main(){
map<string,int> mpp;
mpp["abhi"]=1021;
mpp["atg"]=11;
mpp["singhal"]=21;
mpp["abhi"]=1;// the abhi will store 1 , it will over-right 1021
// mpp.emplace("abhi",1);
//it is same as above statement

mpp.erase(map.begin());
mpp.clear();
auto it=mpp.find("abhi");//it will give first occurance of abhi
if(mpp.empty()){
    cout<<"yes it is empty";
}
mpp.count("abhi");//always return 1
//instance of abhi

// how to print
for(auto it:mpp){
    cout<<it.first<<" "<<it.second<<endl;
}// we can use dot above as auto:it makes a pair
for(auto it=mpp.begin();it!=mpp.end();it++){
    cout<<it->first<<" "<<it->second<<endl;
}//we will use -> as it is an iterator




// 
unordered_map<int,int> mpp;
// same function as above

// 
// pair class
pair<int,int> pr={1,2};
pair<pair<int,int>,int> pr={{1,2},2};
cout<<pr.first.second<<endl;
pair<pair<int,int>,pair<int,int>> pr={{1,2},{3,2}};
cout<<pr.first.first<<endl;//1
cout<<pr.second.first<<endl;//3
// pair is a single not a container

vector<pair<int,int>> vec;
set<pair<int,int>> st;
map<pair<int,int>> mp;
// unorder_map can not store pair 


// 
multi_map<string,int> mlmp;
mlmp.emplace("abhi",2);
mlmp.emplace("abhi",42);// it will store both value
return 0;
}