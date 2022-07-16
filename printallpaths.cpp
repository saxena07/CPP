#include<iostream> 
#include<vector> 
using namespace std;

bool isvalid(int x , int y, int i, int j){
  if(i<x && j<y && i>=0 && j>=0) return true;
  return false;
}

void printall(int i, int j, int x, int y, vector<vector<int>> mat, vector<int> path){
   if(i==x-1 && j==y-1){
     path.push_back(mat[i][j]);
     for (int x = 0; x < path.size(); x++) cout<<path[x]<<" ";
     cout<<endl;
     return;
   }
   if(isvalid(x,y,i,j)){
       path.push_back(mat[i][j]);
       printall(i+1,j,x,y,mat,path);
       printall(i,j+1,x,y,mat,path);
   }
}

void printAllPaths(vector<vector<int>> mat, int x, int y){
   printall(0,0,x,y,mat, {});
   return;
}

int main()
{
    vector<vector<int>> mat= { {1, 2, 3}, {4, 5, 6} ,{7,8,9}};
    printAllPaths(mat, 3, 3);
    return 0;
}