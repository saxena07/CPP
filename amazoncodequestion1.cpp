#include <bits/stdc++.h>
using namespace std;

int fun(int n, int arr[], int m){
    int sum=0;
    for(int i=0;i<n;i++)  sum+= arr[i];
    int sumofwind=0;
    for(int i=0;i<m;i++)  sumofwind+= arr[i];
    int ans=sumofwind;
    int prevele= arr[0];
    for(int i=m;i<n;i++){
        sumofwind= sumofwind-prevele+arr[i];
        ans=max(ans, sumofwind);
        prevele=arr[i-m+1];
    }
    cout<<ans<<endl;
    return sum-ans;
}


int main(){
    int n=16, m=1;
    int arr[n]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    cout<<fun(n, arr, m);
    return 0;
}
