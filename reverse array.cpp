#include<iostream>
using namespace std;


int main(){
     int size;
     cin>>size;
     int a[size];
     for (int i = 0; i < size; i++)
     {
        cin>>a[i];
     }
     
     for (int i = 0; i <= (size-1)/2; i++)
     {
        int t=a[i];
        a[i]=a[size-1-i];
        a[size-1-i]=t;
     }

     for (int i = 0; i < size; i++)
     {
        cout<<a[i]<<" ";
     }
     
    return 0;
}