#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int> & arr){
int count = arr.size(),n=0,p=0;
for (int i = 0; i < count; i++) {if(arr[i]<0) n++;}
p=count-n;
if(p>n) sort(arr.begin(),arr.end());
else sort(arr.begin(),arr.end(), greater<int>());
for (int i = 0; i < count; i++)
{
    /* code */ cout<<arr[i]<<" ";
}


}



int main(){
    vector<int> a={-2,-3,1,-2,5};
    rearrange(a);
    return 0;
}