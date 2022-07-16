#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cout<<"Enter your size of array :";
    cin>>size;
    int a[size];
    cout<<endl<<"Enter your (sorted) array :";
    for(int i=0;i<size;i++){
     cin>>a[i];
    }
    cout<<endl<<"your (sorted) array is :";
    for(int i=0;i<size;i++){
     cout<<a[i]<<"_";
    }
    int jump=sqrt(size),ele,flag=0,i;
    cout<<jump<<endl;
    cout<<endl<<"Enter the element to be searched :";
    cin>>ele;
    for(i=0;i<size;i=i+jump){
       if(ele==a[i]){
           cout<<endl<<"Element found at position "<<i+1<<".";
           flag=1;
                        }
       else if(jump>a[i]){
           for(int j=a[i];j>a[i-jump];j--){
             if(a[j]==ele){
                 cout<<endl<<"Element found at position "<<j+1<<".";
                 flag=1;
                 }   
           }
       }
    }cout<<i;

    return 0;
}