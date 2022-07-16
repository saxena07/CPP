 #include<iostream>
 #include<bits/stdc++.h>
using namespace std;

 int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int c=0,l=0,n=nums.size(),m=nums[0];
        for (int i = 0; i <= n; i++)
        { 
            if(nums[i]<=right && m<=right && m>=left && i<n){
                c=c+1;
                
                if(nums[i]>m && nums[i]<=right  && nums[i]>=left)
                m=nums[i];

            }
            else{
                l++;
                
                if(nums[l]<=right)
                m=nums[l];

                i=l-1;
            }

            if(l==n-1 && i==n-1){
                break;
            }
            
        }
        return c;
        

    }


int main(){
vector<int> n={73,55,36,5,55,14,9,7,72,52};
cout<<numSubarrayBoundedMax(n,32,69);
    return 0;
}