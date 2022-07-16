#include<iostream>
using namespace std;
int main(){
    int count,n;
    cin>>count;

    for (int i = 0; i < count; i++)
    {
        cin>>n;
        int a[n];
        for (int j = 0; j < n; j++)
        {
          cin>>a[j];
        }

        for(int j=n-1; j>=0; j--){
           if(a[j]!=0 && a[j]!=1){
               int k = a[j];
               int j1=j;
               while(k>0 && j>=0){

                   
                   a[j]=1;
                   j--;
                   k--;
                   
                   if(a[j]>k){
                    
                     break;}
                   
           
               }j++;
           }

        }

        for (int j = 0; j < n; j++)
        {
            cout<<a[j]<<" ";
        }cout<<endl;
        
    }
        return 0;
}
