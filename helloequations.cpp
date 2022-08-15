#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main(){

    int n;
    cin>>n;
    while(n-->0){
        int X;
        cin>>X;
        bool f=false;
        for(int a=1;a<=X/2;a++){
            int b=X-(2*a);
            if(b==0) break;
            if(b%(2+a)==0){
                f=true;
                cout<<"YES"<<endl;
                break;
            }
        }
        if(!f) cout<<"NO"<<endl;
    }

    return 0;
}