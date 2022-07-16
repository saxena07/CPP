#include<iostream>
#include<vector>
using namespace std;

	bool issafe(int i, int j, vector<vector<int>> grid, int m , int n){
	  if(i>=0 && j>=0 && i<m && j<n) return 1;
	  return 0;
	}
	
	void nearestutil(int i, int j, int i1, int j1, int m, int n,vector<vector<int>> grid, vector<vector<int>>& ans){
	    if(issafe(i1,j1,grid, m, n)) {
	        int a= i1-i, b=j1-j;
	        int d= abs(a)+abs(b);
            cout<<d<<" "<<ans[i][j]<<endl;
	        if(d<ans[i][j] && grid[i1][j1]==1) ans[i][j]=d;
            cout<<d<<" "<<ans[i][j]<<endl;
	        return;
	    }
	    if(issafe(i+1,j,grid,m,n)) nearestutil(i,j,i+1,j,m,n,grid,ans);
	    if(issafe(i-1,j,grid,m,n)) nearestutil(i,j,i-1,j,m,n,grid,ans);
	    if(issafe(i,j+1,grid,m,n)) nearestutil(i,j,i,j+1,m,n,grid,ans);
	    if(issafe(i,j-1,grid,m,n)) nearestutil(i,j,i,j-1,m,n,grid,ans);
	}
	
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<int>> ans (grid.size(), vector<int> (grid[0].size(), 9999));
	    int m=grid.size(), n=grid[0].size();
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1) ans[i][j]=0;
	            else nearestutil(i,j,i,j,m,n,grid,ans);
	        }
	    }
	    return ans;
	}

int main(){

    vector<vector<int>> v={{0,1,1,0},{1,1,0,0},{0,0,0,0}};
    vector<vector<int>> ans=nearest(v);
    for (int i = 0; i < ans.size(); i++)
    {   for (int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
    } cout<<endl;
        /* code */
    }
    

    return 0;
}