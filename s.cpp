#include<bits/stdc++.h>
#include<string>
using namespace std;

 string kthDistinct(vector<string>& arr, int k) {
        string b="";
        int c=0,flag=0;
        
        for(int i=0; i< arr.size(); i++)
        { flag=0;                         
         
         for(int j=0; j< arr.size(); j++){
             if(arr[i]==arr[j] && j!=i){
                  flag=1;
                   break;}
          
         }
         
          if(flag==0) c++;
          if(c==k) cout<<arr[i];                           
        
        }
        
        return b;
    }

int main(){
    vector<string> a = {"d","b","c","b","c","a"};
    kthDistinct(a, 2);

	return 0;
}
