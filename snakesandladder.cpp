#include<iostream>
// #include<std/c++>
#include<vector>
using namespace std;

    vector<int> coordinates(int n, int currans){
        int i=currans/n;
        int j=currans%n;
        int x,y;
        if(i%2==0){
            if(j==0){
                y=0; x=n-i;
            }
            else{
                y=j-1; x=n-1-i;
            }
        }
        else{
            if(j==0){ 
                y=n-1; x=n-i; 
            }
            else{
                y=n-j; x=n-1-i;
            }
        }
        return {x,y};
    }
    
    void snakesAndLaddersutil(vector<vector<int>>& board, int & ans, int curr, int n, int currans){
        
        if(curr+min(curr+6,n*n)>=n*n){
            ans=min(ans, currans+1);
            return;
        }
        if(currans+1>=ans) return;
        
        for(int i=curr+1;i<=min(curr+6,n*n);i++){
            
            vector<int> a=coordinates(n,currans);
            
            if(board[a[0]][a[1]]!=-1) 
                snakesAndLaddersutil(board, ans, board[a[0]][a[1]],n,currans+1);
           else 
                snakesAndLaddersutil(board, ans, i,n,currans+1);
        }
        
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int ans=INT_MAX;
        snakesAndLaddersutil(board, ans, 1,board.size(), 0);
        return ans;
    }

int main(){
     cout<<"hello";
     vector<vector<int>> b={{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
     cout<<snakesAndLadders(b);

    return 0;
}    