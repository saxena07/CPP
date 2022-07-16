#include<iostream>
#include<vector>
#include<string>
using namespace std;

 int min1(int a, int b, int c){
        if(a<=b && a<=c) return a;
        else if(b<=a && b<=c) return b;
        return c;
    } 
  
    int ed(int i, int j, string s, string t,  vector<vector<int>> &v){
        if(v[i][j]!=-1) return v[i][j];
        if(s[i-1]==t[j-1]) return v[i][j]=min1(ed(i-1,j, s, t, v)+1, ed(i,j-1, s, t, v)+1, ed(i-1,j-1, s, t, v));
        else return v[i][j]=min1(ed(i-1,j, s, t, v)+1, ed(i,j-1, s, t, v)+1, ed(i-1,j-1, s, t, v)+1);
    }
  
    int editDistance(string s, string t) {
        vector<vector<int>> v(s.size()+1, vector<int> (t.size()+1, -1));
        for(int i=0;i<=s.size();i++) v[i][0]=i;
        for(int i=0;i<=t.size();i++) v[0][i]=i;
        int k= ed(s.size(), t.size(), s, t, v);
        // for(int i=0;i<=s.size();i++){ for(int j=0;j<=t.size();j++)  cout<<v[i][j]<<" ";
        // cout<<endl;}cout<<endl;
        return k;
    }

int main(){
 string a="gfg", b="gfgfg";
 cout<<editDistance(a,b);
 return 0;
}