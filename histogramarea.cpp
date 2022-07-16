#include<iostream>
#include<stack>
#include<vector>
using namespace std;


    long long getMaxArea(long long arr[], int n)
    {
       vector<long long> ns(n);
       vector<long long> ps(n);
       ns[n-1]= n;
       ps[0]= -1;
    //   if(arr.size()==0) return v;
       stack<long long> s1;
       stack<long long> s2;
       s1.push(n-1);
       for(int i=n-2;i>=0;i--){
               while(!s1.empty() && arr[s1.top()]>=arr[i]) s1.pop();
               if(s1.empty()) ns[i]=n;
               else ns[i]=s1.top();
                   s1.push(i);
           }
            s2.push(0);
       for(int i=1;i<=n-1;i++){
               while(!s2.empty() && arr[s2.top()]>=arr[i]) s2.pop();
               if(s2.empty()) ps[i]=-1;
               else ps[i]=s2.top();
                   s2.push(i);
           }
           for (int i = 0; i < n; i++)
            cout<<ns[i]<<" ";
            cout<<endl;
           for (int i = 0; i < n; i++)
            cout<<ps[i]<<" ";
           cout<<endl;
        vector<long long> ans(n);
        long long maxi=0;
        for(int i=0;i<n;i++){
            long long ar=(ns[i]-ps[i]-1)*arr[i];
            maxi=max(maxi, ar);
        }
        return maxi;
    }

int main(){
    long long arr[7]={9, 10, 4, 10, 4, 5, 16};
    cout<<getMaxArea(arr, 7);
    return 0;
}    