#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//                         COUNT SORT

//                         QUICK SORT

int Partition (int arr[], int low, int high)
{
         int pivot = arr[high]; // selecting last element as pivot
         int i = low; // index of smaller element
         for (int j = low; j <= high- 1; j++) 
            {  
         if (arr[j] <= pivot) 
           { i++; 
           
   int temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   
         }
   } 
   int temp=arr[i+1];
   arr[i+1]=arr[high];
   arr[high]=temp;

    return (i + 1);
 } 

void quicksort(int a[], int p, int r) 
{ 
   if(p < r) 
     { int q = Partition(a, p, r);               
            quicksort(a, p, q-1); 
            quicksort(a, q+1, r);
 }
 } 


//                         MERGE SORT 
void merge(int A[],int l1, int mid1,int r1){
    int n1=mid1-l1+1;
    int n2=r1-mid1;

    int a[n1],b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i]=A[l1+i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = A[mid1+i+1];
    }

    int i=0,j=0,k=l1;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            A[k]=a[i];
            i++;
            k++;
        }
        else{
            A[k]=b[j];
            j++;
            k++;
        }
    }
     while (i<n1){
         A[k]=a[i];
            i++;
            k++;
        }
        
     while (j<n2){
         A[k]=b[j];
            j++;
            k++;
        }
}
void mergesort(int A[],int l,int r){
   if (l >= r)
        return; // Returns recursivly
 
   
       int mid = l+(r-l)/2;
       mergesort(A,l,mid);
       mergesort(A,mid+1,r);

       merge(A,l,mid,r);
}

int main(){
    int count;
    cin>>count;
    int a[count];

    for (int i = 0; i < count; i++)
    {
        cin>>a[i];
    }


    // cout<<"Final array : ";
    // for (int i = 0; i < count; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    
    return 0;
}
