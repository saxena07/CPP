#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int N){
     vector<int> fac;
     fac.push_back(1);
     if(N==1) return fac;
     while(N>1){
     int carry=0,p;
        for (int i = fac.size()-1; i>=0; i--)
        {  p=(fac[i]*N)+carry; 
            carry=p/10; 
            p = p%10;
            fac[i]=p;
        }
        while(carry>0){
            fac.push_back(fac[fac.size()-1]);
            for (int i=fac.size()-2; i>0; i--) fac[i]=fac[i-1];
            fac[0]=carry%10;
            carry=carry/10;
        }
         N--;
     }
     return fac;
    }

int main(){
vector<int> a=factorial(11);
for (int i = 0; i < a.size(); i++) cout<<a[i];

    return 0;
}