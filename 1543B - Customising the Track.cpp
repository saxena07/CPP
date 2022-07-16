#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int main(){
    int n,size;
    
    cin>>n;
    for(int t=0;t<n;t++){
        cin >>size;
        vector< long long int> array(size);
        for (auto& element : array)
         {cin >> element; }
        long long int sum = 0, d, r;
        //sum=accumulate(array.begin(),array.end(),0);
        //cout<<sum<<endl;
        for(int i=0;i<size;i++)
        sum=sum+array[i];
        //cout<<sum<<endl;
        d=sum/size;
        r=sum%size;
        long long int f=0;
        vector<long long int> array1(size,d);
        /*for(int i=0;i<size;i++){
            if(i<r){
                array[i]=d+1;
            }
            else{
                array[i]=d;      
                      }
        }
        */
       for(int i=0;i<r;i++)
       array1[i]=array1[i]+1;
        //for(int i=0;i<r;i++){
            //for(int j=r;j<size;j++){
              //f=f+abs(array1[i]-array1[j]);
              f=(size-r)*r;  
            //}
        //}

        cout<<f<<endl;
             }

    return 0;
}
