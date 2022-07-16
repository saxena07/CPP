#include<iostream>
#include<vector>
using namespace std;
vector<int> k;
bool findsum(vector<int> arr, int N, int sum, int stn, int start){
if(start>N) return 0;
if(stn>sum) return 0;
if(stn==sum) return 1;

for (int i = start; i < N; i++)
{
    if(stn+arr[i]<=sum){
        stn+=arr[i];
        k.push_back(arr[i]);
        if(findsum(arr, N, sum, stn,i+1)) return 1;
        k.pop_back();
        stn-=arr[i]; 
    }

}
return 0;
}

int main(){
    vector<int> arr={478 ,757 ,314 ,471 ,729 ,100 ,459 ,618};
    int N =arr.size(), sum=0;
    for (int i = 0; i < N; i++)
    {sum+=arr[i];}
    if(sum%2==0) cout<<findsum(arr,N,sum/2,0,0)<<endl;
    else cout<<0<<endl;
    for (int i = 0; i < k.size(); i++) cout<<k[i]<<" ";
    
    
    return 0;
}