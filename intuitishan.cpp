#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> v, int n){
    int nz=0;
    for(int i=0;i<n;i++) if(!v[i]) nz++;
    vector<int> sa(n, 1);
    for(int i=0;i<nz;i++) sa[i]=0;
    int ans=0;
    for(int i=0;i<n;i++) if(v[i]!=sa[i]) ans++;
    return ans/2;
}

int main(){
    vector<int> v={1,0,1,1,1,0};
    int  n=6;
    cout<<fun(v, n);
    return 0;
}