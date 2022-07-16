#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> & s,int index1, int index2){
    int temp=s[index2];
    s[index2]=s[index1];
    s[index1]=temp;
}

int main(){
    vector<int> a={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 1};
 int count=a.size();
 int low=0, mid=0, high=a.size()-1;
 while(mid<=high){
    
    switch(a[mid]){
    case 0:
      swap(a,low,mid);
      low+=1, mid+=1;
      break;      
    
    case 1:
      mid++; 
      break;      
    
    case 2:
      swap(a,high,mid);
      high-=1;
      break;      
    }
    

 }

 for (int i = 0; i < count; i++) cout<<a[i]<<" ";



    return 0;
}