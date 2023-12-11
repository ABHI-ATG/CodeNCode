#include <bits/stdc++.h>
using namespace std;

//ATG


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> strong;
	    vector<vector<int>> id;
	    int arr[n][m];
	    int max=-1;
	    for(int i=0;i<n;i++){
	        max=-1;
	        int ind=0;
            vector<int> temp;
            vector<int> temp2;
	        for(int j=0;j<m;j++){
	            cin>>arr[i][j];
	            if(arr[i][j]>max){
	                max=arr[i][j];
	                ind=j;
	            }
	        }
            temp.push_back(max);
            temp2.push_back(ind);
	        strong.push_back(temp);
	        id.push_back(temp2);
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(j==id[i][0]){
                    continue;
                }
	            if(strong[i][0]==arr[i][j]){
	                max=arr[i][j];
	                strong[i].push_back(max);
                    id[i].push_back(j);
	            }
	        }
	    }
	  for(int i=0;i<n;i++){
        for(int j=0;j<strong[i].size();j++)
        {
            cout<<"a"<<strong[i][j] << " ";
            cout<<id[i][j]<<endl;
        }   
   
        }
	   int check=0;
	   for(int i=0;i<n;i++){
	       int test=0;
           for(int k=0;k<strong[i].size();k++){
               for(int j=0;j<n;j++){
	            if(arr[i][id[i][k]]<strong[i][k]){
	               test=1;
	               break;
	           }
	       }
	       if(test==0){
	           check=1;
	           break;
	       }
           }
	   }
	   if(check==1){
	       cout<<"YES"<<"\n";
	   }else{
	       cout<<"NO"<<"\n";
	   }
	return 0;
}
