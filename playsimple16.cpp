#include <bits/stdc++.h>
using namespace std;

int playsimplefunc(int emp, int lang, vector<vector<int>>& grid){
    vector<int> parent(lang+1, -1);
    int comp=0;

    for(int i=0;i<emp;i++){
        if(grid[i][0]==0) {comp++; continue;}
        else{
            int p=-1; bool flag=0;
            for(int j=1;j<=grid[i][0];j++){
                if(parent[grid[i][j]]!=-1){
                    p=parent[grid[i][j]]; flag=1; break;
                }
            }
            for(int j=1;j<=grid[i][0];j++){
                if(flag) parent[grid[i][j]]=p;
                else parent[grid[i][j]]=i;
            }
            if(!flag) comp++;
        }
    }
    for(int i=0;i<=lang;i++) cout<<parent[i]<<' ';
    cout<<endl;
    return comp;
}


int main(){
    int emp=7, lang=11;
    vector<vector<int>> grid={{0}, {3,1,2,3}, {2,4,7}, {2,5,4}, {3,1,6,8}, {2,6,9}, {3,4,10,11}};
    cout<<playsimplefunc(emp, lang, grid)-1;
    return 0;
}