#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b){
    int n1=a.size(), n2=b.size(), i=0, j=0;
    vector<int> c;
    while(i<n1 && j<n2){
      if(abs(a[i])<=abs(b[j])){
        c.push_back(a[i]*a[i]);
        i++;
      }else {c.push_back(b[j]*b[j]); j++;}
    }
    while(i<n1){ c.push_back(a[i]*a[i]); i++;}
    while(j<n2){ c.push_back(b[j]*b[j]); j++;} 
    return c;
}


int main(){
    int arr[6]={-9,-1,0,1,2,6};
    int n=6, in=0;
    if(arr[0]>=0) {
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        return 0;
    }
    vector<int> arr1, arr2;
    for(int i=1;i<n;i++){
       if(arr[i]>=0){
           in =i-1;
           break;}
    } for(int i=in+1;i<n;i++){ arr1.push_back(arr[i]); }
    for(int i=in;i>=0;i--) arr2.push_back(arr[i]);
    
    vector<int> ans(n);
    ans=merge(arr1, arr2);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
        return 0;
}