#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        // cout<<"hehe";
        int endr=r-1, endc=c-1, starc=0, starr=1;
        int i1=0, j1=0;
        vector<int> v;
        // cout<<v.size();
        while(v.size()<(r*c))
        {
        for(int i=j1;i<=endc;i++){ v.push_back(matrix[i1][i]);  j1=i; }
        endc--; i1++;
        if(v.size()==(r*c)) break;
        // cout<<i1<<" "<<j1<<endl;
        for(int i=i1;i<=endr;i++){ v.push_back(matrix[i][j1]);  i1=i; }
        endr--; j1--;
        if(v.size()==(r*c)) break;
        // cout<<i1<<" "<<j1<<endl;
        for(int i=j1;i>=starc;i--){ v.push_back(matrix[i1][i]);  j1=i; }
        starc++; i1--;
        if(v.size()==(r*c)) break;
        // cout<<i1<<" "<<j1<<endl;
        for(int i=i1;i>=starr;i--){ v.push_back(matrix[i][j1]);  i1=i; }
        starr++; j1++;
        if(v.size()==(r*c)) break;
        // cout<<i1<<" "<<j1<<endl;
        // cout<<" size : "<<v.size()<<endl;
        }
        // cout<<" size : "<<v.size()<<endl;
        // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        return v;
        
    }

int main()
{
    
        // cout<<" hehe";
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    vector<vector<int>> matrix={ {1, 2, 3, 4}, {5, 6, 7, 8},  {9, 10, 11, 12}};

    vector<int> v= spirallyTraverse(matrix, 3, 4);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    return 0;
}