#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

    // public:
    bool issafe(int i, vector<int> &seats){
        // if(seats[i]) return false;
        // if(i==0 && seats[i+1]==0) return true;
        // else if(i==seats.size()-1 && seats[i-1]==0) return true;
        //     if(seats[i-1]==0 && seats[i+1]==0) return true;
            return false;
    }
    
    // bool isputil(int n, vector<int> seats, int m, int in, vector<vector<int>> &dp){
    //     if(n==0) return true;
    //     if(in==m){
    //         if(n==0) return true;
    //         else return false;
    //     }
    //     if(dp[n][in]!=-1) return dp[n][in];
    //     if(issafe(in, seats)) {seats[in]=1;
    //     return dp[n][in]=isputil(n-1, seats, m, in+1, dp);}
    //     return dp[n][in]=isputil(n, seats, m, in+1, dp);
    // }
    
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        // for(int i=0;i<m;i++){
            vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
            // for(int i=0;i<=n;i++) dp[i][m]=false;
            for(int i=0;i<=m;i++) dp[0][i]=true;
            
            for(int in=m-1;in>=0;in++){
                for(int n1=1;n1<=n;n1++){
                    cout<<in<<" "<<n1<<endl;
                if(issafe(in, seats)) {seats[in]=1;
                dp[n1][in]=dp[n1-1][in+1];}
                else dp[n1][in]=dp[n1][in+1];
                    
                }
            }
        return dp[n][0];
        //  return isputil(n, seats, m , 0, dp); 
    }

int main(){
    vector<int> v={0,0,1,0,0,0,1};
    cout<<is_possible_to_get_seats(2, 7, v);
    return 0;
}    