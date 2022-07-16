#include<iostream>
#include <bits/stdc++.h>
// #include<algorithm>
using namespace std;

bool check(vector<vector<int>> mat, int c, int V, int dst){
if(c==dst) return true;
for(int i=0;i<V;i++) if(mat[c][i]) return true;
return false;
}

int networkflow(vector<vector<int>>& mat, int V,int src, int dst){
    
vector<bool> visited(V);
int ans=0;
stack<int> s;
vector<int> path;

do{

path.clear();
while(!s.empty()) s.pop();
for(int i=0;i<V;i++) visited[i]=false;

s.push(src);
while(!s.empty()){
    int curr=s.top();
    s.pop();
    visited[curr]=true;
    path.push_back(curr);
    if(curr==dst) break;
    for(int i=0;i<V;i++){ if(!visited[i] && mat[curr][i] && check(mat, i ,V, dst)){ s.push(i);}}
}

if(path[path.size()-1]!=dst) break;
// for(int i=0;i<path.size();i++) cout<<path[i]<<" "; cout<<endl;
int min=INT_MAX;
for(int i=0;i<path.size()-1;i++) if(mat[path[i]][path[i+1]]<min) min=mat[path[i]][path[i+1]];
for(int i=0;i<path.size()-1;i++) mat[path[i]][path[i+1]]-=min;
ans+=min;
// cout<<ans<<" "<<min<<endl;
// printmat(mat);
}while(path[path.size()-1]==dst);

return ans;
}

int main(){
vector<vector<int>> mat={{0,2,10,0,0,0},{0,0,0,6,0,0},{0,3,0,0,4,0},{0,0,0,0,7,12},{0,0,0,0,0,12},{0,0,0,0,0,0}};
int s=0,d=5,V=6;
// cout<<check(mat, 2,V, d);
cout<<"Max flow of the given network is : "<<networkflow(mat,V,s,d);
return 0;
}

