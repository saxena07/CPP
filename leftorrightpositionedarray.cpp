#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool leftRight(int arr[],int n)
    {vector<int> a(*max_element(arr,arr+n));
     for(int i=0; i<n; i++) a[arr[i]]++;
     for(int i=0;i<(n+1)/2;i++){
     bool a1=(a[i]==0 && a[n-1-i]==2),b1=(a[i]==1 && a[n-1-i]==1),c1=(a[i]==2 && a[n-1-i]==0);
     if(a1||b1||c1) continue;
     else return 0;
     } return 1;
    }

int main(){
    int a[]={1,2,3,4,5,6,7,8,9,9};
    cout <<leftRight(a,10);
    return 0;
}    