#include<bits/stdc++.h>
using namespace std;

int ans =1e9;
int part(vector<int> nums, int n, int sum, int totsum, vector<int> &dp){
if(n<0) return 0;
if(dp[sum]!=-1) return dp[sum];
int take=1e9;
if(nums[n]<=sum) take=part(nums, n-1, sum-nums[n], totsum, dp);
int nottake=part(nums, n-1, sum, totsum, dp);
dp[sum]=abs((2*sum)-totsum);
return dp[sum];
}

// int part(vector<int> nums, int n){
// vector<vector<int>> dp;
// int totsum=0;
// for (int i = 0; i < n; i++) totsum+=nums[i];
// return partutil(nums, n-1, totsum, totsum, dp);
// }

int main(){
    vector<int> nums={1,1,3,4};
    int ts=0;
    for(int i=0;i<4;i++) ts+=nums[i];
    vector<int> dp(ts+1, -1);
    cout<<part(nums, 3, 9, 9, dp);
    return 0;
}