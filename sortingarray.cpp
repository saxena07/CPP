#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
     *a=*b;
     *b=temp;
     return;
}
//                                                  B U B B L E - S O R T 
void bubblesort(int A[], int size){
for (int i = 0; i < size; i++)
{ int flag=0;
  for (int j = 1; j < size-i; j++) if(A[j]<A[j-1]) { swap(&A[j],&A[j-1]);  flag=1; }
  if(flag==0) break;
}
}
//                                                  S E L E C T I O N - S O R T 
void selectionsort(int A[], int size){
for (int i = 0; i < size; i++)
{int min= i;
 for (int j = i+1; j < size; j++) if(A[j]<A[min]) min = j;
 if(min!=i) swap(&A[min],&A[i]);
}
return;
}
//                                                  I N S E R T I O N - S O R T 
void insertionsort(int A[], int size){
  for (int i = 1; i < size; i++)
  {int current = A[i], j= i-1;
  while(A[j]>current && j>0) {A[j+1]=A[j]; j--;}
    A[j+1]=current;
  }
  return;
}
//                                                      M E R G E - S O R T
void merge(int A[], int l , int mid, int r){
  int n1=mid-l+1, n2= r-mid;
  int B[n1], C[n2];
  for (int i = 0; i < n1; i++) B[i]=A[l+i];
  for (int i = 0; i < n2; i++) C[i]=A[mid+1+i];
  int i=0, j=0, k=l;
  while(i<n1 && j<n2){
    if(B[i]<C[j]) A[k++]=B[i++];
    else A[k++]=C[j++];
  }
  while(i<n1)  A[k++]=B[i++];
  while(j<n2)  A[k++]=C[j++];
}

void mergesort(int A[], int l, int r){
  if(l<r){
    int mid= l+ (r-l)/2;
    mergesort(A,l,mid);
    mergesort(A,mid+1,r);
    merge(A,l,mid,r);
  }
}
//                                                       S H E L L - S O R T
void shellsort(int A[], int n){
for (int gap = n/2; gap>0 ; gap/=2)
{ for (int i = gap; i < n; i++)
 { int temp = A[i], j;
  for (j = i; (j>=gap) && (A[j-gap]>temp); j-=gap) A[j]= A[j-gap];
  A[j]=temp; 
 }  
}
}
//                                                      Q U I C K - S O R T
int partition( int arr[], int low, int high )
  {
  int left= low, right= high;
  int pivot_item =  arr[low];
  while ( left < right ) {
    while( arr[left] <= pivot_item ) left++;
    while( arr[right] > pivot_item ) right--;
    if ( left < right ) swap(&arr[left],&arr[right]);
    }
  swap(&arr[low],&arr[right]);
  // arr[right] = pivot_item;
  return right;
  }
// int Partition (int arr[], int low, int high)
// {        int pivot = arr[high]; 
//          int i = low-1; 
//          for (int j = low; j <= high- 1; j++){ 
//            if (arr[j] <= pivot) 
//            { i++; 
//            swap(&arr[i], &arr[j]);
//          }
//          }
//            swap(&arr[i+1], &arr[high]);
//     return (i + 1);
//  } 

void quicksort(int A[],int l, int h){
if(l<h){int j= partition(A,l,h);
quicksort(A,l,j-1);
quicksort(A,j+1,h);
}
}


int main(){
    int size = 20;
  int A[20]={6 ,6 ,8 ,19 ,8 ,10 ,19 ,14 ,20 ,18 ,5 ,11 ,20 ,6 ,10 ,7 ,15 ,8 ,8 ,9};
  bubblesort(A,size);
  int ans=0;
  for (int i = 0; i < 20; i++) ans+=A[i]*i;
  cout<<ans<<endl<<ans%1000000007;

  return 0;
}