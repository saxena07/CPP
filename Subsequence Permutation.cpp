#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
    int n;
    cin>>n;
       int m=0,c;
     std::string s,p;
    for(int i=0;i<n;i++){
        c=0;
        cin>>m;
        cin>>s;
        p.assign(s);
        sort(p.begin(),p.end());
        for(int i=0;i<m;i++){
            if(p[i]!=s[i]){
                c=c+1;
            }
        }cout<<c<<endl;
    }
    return 0;
}