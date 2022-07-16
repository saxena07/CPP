#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void twodsord(vector<vector<int>> v, int data, int m , int n){
pair<int, int> p;
p.first=0;
p.second=n-1;
while (p.first<=m-1 && p.second>=0)
{
if(v[p.first][p.second]==data){
    cout<<"Element found at : "<<p.first<<" & "<<p.second<<" . "<<endl;
    return;
} else if(data<v[p.first][p.second]) p.second--;
 else if(data>v[p.first][p.second]) p.first++;
}
    cout<<"data not found !!!"<<endl;
    return ;
}

int main(){
    vector<vector<int>> v={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int data=160;
twodsord(v, data, v.size(), v[0].size());
    return 0;
}