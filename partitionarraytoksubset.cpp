#include<iostream>
#include<vector>
using namespace std;

bool valid(vector<int> sum, int k, int s){
      for(int i=0;i<k;i++) if(sum[i]!=s) return false;
      return true;
  }
  void prin(vector<int> sum , int k){
      for (int i = 0; i < k; i++)
      {
          cout<<sum[i]<<" ";
      }cout<<endl;
      return;      
  }
  
  bool kpart(vector<int> sum, int s, int n, int k, int a[], int start){
      if(start>=n-1){
          prin(sum, k);
          if(valid(sum, k, s)) return true;
          else return false;
      }
      for(int i=start;i<n;i++){
          for(int j=0; j<k; j++){
              if(sum[j]==s) continue;
              else if(sum[j]+a[i]<=s){
                  sum[j]+=a[i];
                  if(kpart(sum,s,n,k,a,i)) return true;
                  sum[j]-=a[i];
            }
          }
      }
      return false;
  }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
     int s=0;
     for(int i=0;i<n;i++) s+=a[i];
     if(s%k!=0) return false; 
     else s=s/k;
     vector<int> sum(k,0);
     return kpart(sum, s, n, k, a, 0);
     
    }


int main(){
    int a[]={2,1,4,5,6};
    cout<<isKPartitionPossible(a,5,3)<<endl;
    return 0;
}