#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<bool>> visited(3,vector<bool> (10,false));
vector<int> im={1,0,-1,0};
vector<int> jm={0,1,0,-1};

bool isvalid(int i, int j, int mat[3][10]){
   if(i<3 && j<10 && i>=0 && j>=0 && mat[i][j]==1) return true;
   return false;
}

void findLongestPath(int mat[3][10], int &ans, int i, int j, int anstillnow){

if(!isvalid(i,j,mat)){
    ans=max(ans, anstillnow);
    return;
}

for (int a = 0; a < 4; a++)
{
if(isvalid(i,j,mat) && visited[i][j]==false){
    anstillnow+=1;
    visited[i][j]=true;
 findLongestPath(mat, ans, i+im[a], j+jm[a] ,anstillnow);
    anstillnow-=1;
    visited[i][j]=false;
}
}

return;
}

int main()
{
    // input matrix with hurdles shown with number 0
    int mat[3][10] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
    int ans=-1;
    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, ans, 0, 0, 0);
    cout<<ans<<endl;
    return 0;
}