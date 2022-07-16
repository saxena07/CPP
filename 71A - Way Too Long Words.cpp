#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int j=0;j<n;j++){
    char s[100];
    cin>>s;
    if(strlen(s)==1)
    cout<<s<<endl;
    else if((strlen(s)-2)>=9)
    cout<<s[0]<<strlen(s)-2<<s[strlen(s)-1]<<endl;    
    else
    cout<<s<<endl;
        }
    return 0;
}
