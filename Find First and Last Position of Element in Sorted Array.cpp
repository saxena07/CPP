#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int bs(vector<int>& n, int b, int e, int target){
       
        int f=0;
         if(b<e){
              int mid = (b+e)/2;
            if(n[mid]==target){
                return mid;
            }
             else if(target>n[mid])
                 bs(n,mid+1,e,target);
             else
                 bs(n,b,mid,target);
        }

            return -1;
        
        
    }

    vector<int> searchRange(vector<int>& nums, int target) {
     vector<int> a={-1,-1};
        int q= bs(nums,0,nums.size(),target);
        if(q==-1){
            return a;
        }
        int e=q;
        while(e+1<nums.size() && nums[e+1]==target) ++e;
        while(q-1>-1 && nums[q-1]==target) --q;


        return {q,e};
        
    }
    


int main(){
  vector<int> w={1,3};
   vector<int> q = searchRange(w,1);
   cout<<q[0]<<" "<<q[1];
    return 0;
}