#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int i=0, j=nums.size()-1,in=-1;
   do{
        if(target==nums[i])
          {in=i;
          break;}
        if(target==nums[j-i]){
            in=j-i;
            break;
        }  
        i++;
    } while(i<j);
        
        return in;
    }
    

 int binarysearch(vector<int> a, int l, int r, int d){
        if(r>l){
          int mid=(l+r)/2;
            
        if(d==a[mid]){
            return mid;
        }
        if(d<a[mid])
           return binarysearch(a,l,mid,d);
        else
           return binarysearch(a,mid+1,r,d);}
           return -1;
}

// int firstBadVersion(int n) {
//         return bs(1,n);
//     }

// int bs(int b, int e){
//    if(b<e){ 
//     int m=b+e/2;
//         if(m==1) return 1;
//         if(isBadVersion(m)==true){
//             if(isBadVersion(m-1)==false)
//                   return m;
//             else
//                   return bs(b,m);
//         }
//         else
//             return bs(m+1,e);
//    }
// }


int main(){
    vector<int> v={2};
    return 0;
}