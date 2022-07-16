#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max1(int a, int b, int c){
if(a>=b && a>=c) return a;
else if(b>=a && b>=c) return b;
else return c;
}

int fun(int w[], int v[], int m, int in, vector<vector<int>> &dp )
{
if(in<0) return 0;
// if(in==0){
//     if(m-w[0]>=0) return v[0];
//     else return 0;
// }
if(dp[in][m]!=-1) return dp[in][m];
int b=0, c=0 , a=0;
a=fun(w,v,m,in-1, dp);
if(m-w[in]>=0) {
    b=fun(w,v,m-w[in],in-1, dp)+v[in];
    c=fun(w,v,m-w[in],in, dp)+v[in];
}
return dp[in][m]=max1(a,b,c);
}

int main(){
int w[3]={4,8,2};
int v[3]={7,8,3};
int n=3;
// int dp[n][12];
vector<vector<int>> dp(n,vector<int> (12, -1));
// for(int i=0;i<n;i++) for(int j=0;j<=12;j++) dp[i][j]=-1;
for(int i=0;i<n;i++) dp[i][0]=0;
// for(int i=0;i<12;i++){
//     if(i>=w[0]) dp[0][i]=v[0
//     else dp[0][i]=0;
// }
cout<<"ans : "<<fun(w,v,11,n-1, dp)<<endl;
for(int i=0;i<n;i++){
    for(int j=0;j<12;j++){
        cout<<dp[i][j]<<" ";
    }cout<<endl;
}

return 0;
}
