#include<iostream>
#include<bits/stdc++.h>
using namespace std;

   int deleteAndEarn(vector<int>& nums) {
    int s=*max_element(nums.begin(),nums.end());
    vector<int> a(s+1,0);
    for(int i=0;i<nums.size(); i++) a[nums[i]]+=nums[i];
    vector<int> l(s+4,0);
    for(int i=s;i>=0;i--) l[i]=a[i]+max(l[i+2],l[i+3]); 
        return max(l[1],l[2]);
    }

int main(){
    vector<int> k={3,4,2};
    cout<<deleteAndEarn(k);
   return 0;
}