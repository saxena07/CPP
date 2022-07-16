#include<iostream>
#include<bits/stdc++.h>
using namespace std;

  bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n,0);
        a[n-1]=nums[n-1];
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]==0) a[i]=0;
            else if(i+nums[i]>n) a[i]=*max_element(nums.end()-n+i,nums.end());
            else{
                int max=a[i+1];
                for(int j=i+1;j<=i+nums[i];j++) if(a[j]>max) max=a[j];
                a[i]=max;
            }
        }
        // for(auto it:a) cout<<it<<" ";
        // cout<<endl;
        return a[0];
    }

int main(){
   vector<int> a={3,2,1,0,4};
    cout<<canJump(a);
    return 0;
}