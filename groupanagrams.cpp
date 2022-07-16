#include <bits/stdc++.h>
using namespace std;

string rev(string s){
  string r;
  for(int i=s.size()-1;i>=0;i--) r.push_back(s[i]);
  return r; 
}

vector<vector<string>> anagram(vector<string> s){
    vector<vector<string>> ans;
    vector<bool> v(s.size(), false);
    for(int i=0;i<s.size();i++){
        if(!v[i]){
            v[i]=true;
            string r=rev(s[i]);
            int f=0;
            for(int j=i+1;j<s.size();j++){
                    if(s[j]==r){
                        f=1; 
                        v[j]=true;
                        break;
                    } 
            }
            if(f==1) ans.push_back({s[i],r});
            else ans.push_back({s});
        }
    }
    return ans;
}

int main(){
    vector<string> s={"eat", "fat", "tae"};
    // cout<<rev("eat");
    vector<vector<string>> a=anagram(s);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
