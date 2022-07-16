#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    
    long long min1=a[m-1]-a[0];
    for(int i=0; i<=n-m; i++){
        min1=min(min1,a[i+m-1]-a[i]);
        cout<<a[i-1+m]<<" "<<a[i]<<" = "<< a[i+m-1]-a[i]<<endl;
    }
    return min1;
    }   

int main(){
    cout<<findMinDiff({34 ,88, 89, 39, 67, 71, 85, 57, 18, 7, 61, 50, 38, 6, 60, 18, 19, 46, 84, 74, 59},21,12);
    return 0;
}