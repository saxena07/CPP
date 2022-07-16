#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int mod=1e9+7;

// bool checksort(int arr[], int n){
//     for(int i=1;i<n;i++) if(arr[i]<arr[i-1]) return false;
//     return true;
// }

int main(){
   int count;
   cin>>count;
   for (int i = 0; i < count; i++)
   {
        int n, x;
        cin>>n>>x;
        int arr[n];
        for (int j = 0; j < n; j++) cin>>arr[j];
        int flag=1;
        for(int j=0;j<n-1;j++){

            if(arr[j]>arr[j+1]){
                // cout<<arr[j]<<" "<<arr[j+1]<<endl;
                if(arr[j+1]+arr[j]<=x)
                {
                int a=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=a;
                }
                else 
                {  
                    flag=0;
                    break;
                }

            }
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
   }
    return 0;
}