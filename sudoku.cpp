#include<iostream>
using namespace std;

 char A[9]={'1','2','3','4','5','6','7','8','9'};
    
bool issafe(int x, int y, char t,vector<vector<char>> board){
    for(int i=0;i<9;i++){ if(board[x][i]==t) return false;
                    if(board[i][y]==t) return false; }
     for (int i = 0; i < 3; i++)
     {for (int j = 0; j < 3; j++)
        {if (board[(x - (x % 3)) + i][x - (y % 3) + j] == t)  return false;   }}
return true;                        
}
    
void solveutil(vector<vector<char>>& board, int x, int y){
    if(y>8){x++; y=0;}
    if(x>8) return;
    if(board[x][y]=='.'){for(int i=0;i<9;i++){
        if(issafe(x,y,A[i],board)){
            board[x][y]=A[i];
            solveutil(board,x,y+1);
            board[x][y]='.';
        }
    }}
    return;
}

void solveSudoku(vector<vector<char>>& board) {
    solveutil(board, 0,0);
}

int main(){
    
    
    return 0;

}