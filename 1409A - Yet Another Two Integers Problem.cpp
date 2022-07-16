#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int main(){
    int n;
    
    cin>>n;
    int a,b,d,r;
    for(int t=0;t<n;t++){
    cin>>a>>b;
    d=abs(a-b)/10;
    r=abs(a-b)%10;
    //cout<<r<<endl<<d<<endl;
    if(r==0)
     cout<<d<<endl;
    else{
      d=d+1; 
    cout<<d<<endl;}

    }   
    return 0;
}
