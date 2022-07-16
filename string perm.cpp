#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swapchar(string &s, int pos1, int pos2){
    char a=s[pos1];
    s[pos1]=s[pos2];
    s[pos2]=a;
}

void permbacktrack(int pos, string &s){
    if(pos==s.size()){
        cout<<s<<"  ";
        return;
    }
    for(int i=pos;i<s.size();i++){
        swapchar(s,pos,i);
        permbacktrack(pos+1, s);
    }
}

int main(){

    string s="abcd";
    permbacktrack(0,s);
    
    return 0;
}