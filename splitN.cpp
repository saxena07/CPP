#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int splitn(int n1){
    int cnt=0;
    while(n1){
        n1=n1&(n1-1); 
        cnt++;
        // cout<<n1;
    }
    return cnt;
}

int main() {
	// your code goes here
	int num;
    cin>>num;
    while(num-->0){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        int noo=0;
        for(int i=0;i<n;i++)if(s[i]=='1') noo++;
        if(noo==0) {cout<<n*m<<endl; continue;}
        int non=noo;
        if((non*m)%2!=0) {cout<<0<<endl; continue;}
        noo=(noo*m)/2;
        int d=noo%non;
        int ans=0;
        int ansutil=0;
        // cout<<d<<" ''''''''''''''";
        for(int i=0;i<n;i++){
            if(ansutil==d) ans++;
            else if(ansutil>d) break;
            if(s[i]=='1') ansutil+=1;
        }
        cout<<ans<<endl;
        
    }
	return 0;
}
