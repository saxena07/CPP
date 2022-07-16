#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double a;
        int n=nums1.size()+nums2.size();
        vector<int> arr3(n);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), arr3.begin());
        int mid = n/2;
         if(n%2==0){   
             a=((double)arr3[mid-1]+(double)arr3[mid])/2;
             return a;
         }
         return (double)arr3[mid];
    }

int main(){
   vector<int> a;
   vector<int> b;
    a.push_back(2);
   cout<<findMedianSortedArrays(a,b);

    return 0;
}    