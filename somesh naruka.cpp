#include<iostream>
#include<vector>
using namespace std;


void swap(int *a, int *b){
    int temp=*a;
     *a=*b;
     *b=temp;
     return;
}

void shellsort(int A[], int n){
    int comparisons=0;
for (int gap = n/2; gap>0 ; gap/=2)
{ for (int i = gap; i < n; i++)
 { int temp = A[i], j;
  for (j = i; (j>=gap) && (A[j-gap]>temp); j-=gap){ A[j]= A[j-gap]; comparisons++;}
  A[j]=temp; 
 }  
}
cout<<" No. of comparisons in common shell sort : "<<comparisons+1<<endl;
}

void modifiedshellsort(int A[], int n){
int comparisons=0; 
for (int gap = n/2; gap>0 ; gap/=2)
{for (int i = gap; i < n; i++)
 { int j;
  for (j = i; (j>=gap); j-=gap){ 
  if(A[j-gap]>A[j]) 
  {
  swap(&A[j-gap],&A[j]);
  comparisons++;
  }
  else break;
  }
 }  
}
cout<<" No. of comparisons in modified shell sort : "<<comparisons<<endl;
}

int main(){
     int b[]={90,70,10,45,12,15,18,20,11,8,16,54,32};
    shellsort(b,13);
    for (int i = 0; i < 13; i++) cout<<b[i]<<" ";
  cout<<endl;
    int a[]={90,70,10,45,12,15,18,20,11,8,16,54,32};
    modifiedshellsort(a,13);
    for (int i = 0; i < 13; i++) cout<<a[i]<<" ";
    
    return 0;
}