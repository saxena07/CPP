#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n;
    cin>>n>>k;
    vector<vector<int> >dp(k+1, vector<int> (n+1, 0));
    for(int i=1;i<=n;i++) dp[1][i]=1;
    for(int i=1;i<=k;i++) dp[i][1]=1;
    for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            int ans =0;

            for(int fac=j;fac>=1;fac--){
                if(j%fac==0) ans+=dp[i-1][fac];
            }
            dp[i][j] = ans;
        }
    }
    int finalans=0;
    for(int j=0;j<=n;j++) finalans+=dp[k][j];
    cout<<finalans;
    return 0;
}
