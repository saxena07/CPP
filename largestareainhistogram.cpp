#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getminedge(int hist[], int i, int j){
int min=hist[i], in=i;
for(int k=i;k<j;k++){
  if(hist[k]<min) {
      min=hist[k];
      in=k;
  }
}
return in;
}

int ans=0;

int getMaxArea(int hist[], int n, int i, int j){
    if(i<0 || j>=n) return 0;
    if(i>=j) return 0;
int in=getminedge(hist, i, j);
// cout<<hist[in]<<" "<<endl;
int ansutil=max(getMaxArea(hist,n,i,in-1), getMaxArea(hist, n, in+1, j));
return max(ansutil, hist[in]*(j-i+1));
}



int main()
{
    int hist[] =  {6, 1, 5, 4, 5, 2, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n, 0, n-1);
    return 0;
}