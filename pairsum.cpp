#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<algorithm>
using namespace std;
int c=0;

list<pair <int,int> > pairsum(int A[],int count, int n){
 list<pair <int,int>> L;

 for( int i=0; i<count; i++){
    for (int j = i+1; j < count; j++)
    {
        if(A[i]<A[j] && A[i]+A[j]==n){
            L.push_back(make_pair(A[i],A[j]));
            c++;
        }
    }
    
 }
  return L;


}

int main(){
    int count,n;
    cin>>count;
    cout<<"Enter the number : ";
    cin>>n;

    int a[count];
    for (int i = 0; i < count; i++)
    {
        cin>>a[i];   
         }

    list<pair <int,int> > B  =  pairsum(a,count,n);
    


    return 0;
}