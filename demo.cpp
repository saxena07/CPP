// #include<iostream>
// /*#include<cstdlib>
// #include<bits/stdc++.h>
// #include<stdint.h>
// */
// using namespace std;

// int main(){
//     //unsigned long s=0;
//   /*  long long int s=0;
//     s=781050100LL +282028674LL +664052753LL + 646630006LL + 722021321LL + 737194492LL + 509108352LL;
//     cout<<s<<endl;
//     s=191689628ULL +646033877ULL +109099622ULL +798412961ULL +767677318ULL + 190145527ULL  +199698411ULL;
//     cout<<s<<endl;
//     cout<<sizeof(unsigned long long int);
// */
  
//     int cv;
//     cout<<"Cuantas personas van a participar? "<< endl;
//     cin>> cv ;
//     char nombres[cv];
//     for(int x = 0; x<cv; x++){
//         cin>>nombres;
//         cout<<nombres<< endl;
//     }
//     return 0;

// }
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
      int n=nums.size();
      int p[n],s[n];
      p[0]=1;
      
      for (int i = 0; i < n; i++)
      {
          cout<<nums[i]<<" ";
          /* code */
      }
      
      for (int i = 1; i < n; i++)
      {
          p[i]=p[i-1]*nums[i-1];
      }
      
      s[n-1]=1;

      for (int i = n-2; i >= 0 ; i--)
      {
         s[i]=s[i+1]*nums[i+1];
      }

      for(int i=0;i<n;i++){

          nums[i] = p[i]*s[i];

      }
      return nums;
      
    
}

int main()
{
    vector<int> a={1,2,3,4};
    productExceptSelf(a);
    
        
    return 0;
}