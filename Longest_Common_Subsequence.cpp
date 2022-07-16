#include<iostream> 
#include<bits/stdc++.h> 
using namespace std;
 

int max1(int a, int b, int c){
if(a>=b && a>=c) return a;
if(b>=a && b>=c) return b;
return c;
} 
 
int lcsutil(int n1, int n2, string s1, string s2, vector<vector<int>>& v){
       if(n1<0 || n2<0) return 0;        
       if(v[n1][n2]!=-1) return v[n1][n2];
        return v[n1][n2]=max1(lcsutil(n1-1,n2,s1,s2,v), lcsutil(n1,n2-1,s1,s2,v), s1.compare(s2) == 0 ? 1+lcsutil(n1-1,n2-1,s1,s2,v) : lcsutil(n1-1,n2-1,s1,s2,v));
}
    //Function to find the length of longest common subsequence in two strings.
int lcs(int x, int y, string s1, string s2)
{
        // your code here
        vector<vector<int>> v(x, vector<int> (y,-1));
        return lcsutil(x,y,s1,s2,v);
}

int main(){
    string s1="ABCDGH", s2="AEDFHR";
    cout<<lcs(6,6,s1,s2);
    return 0;
}    