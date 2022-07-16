#include <iostream>
#include <vector>
using namespace std;


bool isvalid(int i, int j, int R, int C, vector<vector<int>> mat){
  if(i>=0 && j>=0 && i<R && j<C) return true;
  return false;
}

bool issafe(int i, int j, int R, int C, vector<vector<int>> mat){
   if(isvalid(i+1,j,C,R,mat) && mat[i+1][j]==0) return false; 
   if(isvalid(i,j-1,C,R,mat) && mat[i][j-1]==0) return false; 
   if(isvalid(i,j+1,C,R,mat) && mat[i+1][j+1]==0) return false; 
   if(isvalid(i-1,j,C,R,mat) && mat[i-1][j]==0) return false;
   return true; 
}

bool fsputil(vector<vector<int>> mat, int i , int j, int R, int C, int distilnow, int & dis){
if(j==C-1 && distilnow<dis){
  dis=distilnow; 
  return true;
}
else if(j==C-1 && distilnow>=dis) return false;

if(isvalid(i,j+1, R,C,mat) && issafe(i,j+1,R,C, mat)){ if(fsputil(mat,i,j+1, R,C,distilnow+1, dis)) return true;}
else if((isvalid(i+1,j, R,C,mat) && issafe(i+1,j,R,C, mat) && fsputil(mat,i+1,j, R,C,distilnow+1, dis)) || (isvalid(i-1,j, R,C,mat) && issafe(i-1,j,R,C, mat) && fsputil(mat,i-1,j, R,C,distilnow+1, dis)))
return true;
else return false;
}

void fsp(vector<vector<int>> mat){
   int dis=100,f=0,distilnow;
   int R=12, C=10;
   for (int i = 0; i < R; i++)
   {
    if(issafe(i,0,R,C,mat))   {if(fsputil(mat,i,0,R,C,0, dis)) f=1;} 
   }
   if(f==0) cout<<"not a path"<<endl;
   else cout<<dis<<" .";
   return;
}


int main() {
   vector<vector<int>> mat =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
    fsp(mat);
	return 0;
}