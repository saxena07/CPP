#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveutil(const vector<int> & A, int sum, int in, vector<vector<int>> &dp){

if(sum==0) return 0;
if(in<0) return 1e6;
if(dp[sum][in]!=-1) return dp[sum][in];
int t=INT_MAX;
if(sum-A[in]>0) t=1+solveutil(A, sum-A[in], in-1, dp);
return dp[sum][in]=min(t, solveutil(A, sum, in-1, dp));
}

int solve(const vector<int> &A) {
int sum=0;
for(int i=0;i<A.size();i++) sum+=A[i];
cout<<sum<<endl<<sum/2<<endl;
vector<vector<int>> dp((sum/2)+1, vector<int> (A.size(), -1));
return solveutil(A, (sum/2), A.size()-1, dp);    
}

int main(){
    vector<int> v={69, 17, 47, 50, 38, 22, 60, 4, 88, 22 };
    cout<<solve(v);
    return 0;
}