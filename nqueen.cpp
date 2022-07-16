#include <iostream>
#include<vector> 
using namespace std;

void prin(vector<vector<int>> ans){
  for (int i = 0; i < ans.size(); i++)
  {
      for (int j = 0; j < ans[i].size(); j++)
      {
          cout<<ans[i][j]<<" ";
      }
      cout<<endl;
  }
  
}

bool safe(int x, int y, vector<vector<int>> board, int n){
 for (int i = 0; i < n; i++) if(board[i][y]==1) return 0;
 for (int i = 0; i < n; i++) if(board[x][i]==1) return 0;
 for (int i = 0; i < n; i++){
     if(x-i>=0 && y-i>=0 && board[x-i][y-i]==1) return 0;
     if(x+i<n && y+i<n && board[x+i][y+i]==1) return 0;
     if(x-i>=0 && y+i<n && board[x-i][y+i]==1) return 0;
     if(x+i<n && y-i>=0 && board[x+i][y-i]==1) return 0;
 }
 return 1;
}

void nqueenutil(vector<vector<int>> &board,vector<vector<int>> &ans,vector<int> &anstillnow,int c, int n){
if(c>=n){
    ans.push_back(anstillnow);
    return;
}
for (int i = 0; i < n; i++)
{
    if(safe(i,c,board, n)){
        board[i][c]=1;
        anstillnow.push_back(i+1);
        nqueenutil(board, ans, anstillnow, c+1, n);
        board[i][c]=0;
        anstillnow.pop_back();
    }
}
return;
}

void nqueen(int n){
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> ans;
    vector<int> anstillnow;
    nqueenutil(board, ans, anstillnow, 0, n);
    prin(ans);
    return;
}

int main(){
    nqueen(6);
    return 0;
}