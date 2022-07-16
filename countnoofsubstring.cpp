#include<iostream>
#include<bits/stdc++.h>
using namespace std;

	long long int ans=0;
  void fun(string s, int i, int kf, int k, unordered_map <char, int> M, int n){
      int j=i;
      while(j<n){
          if(kf==k) ans++;
          M[s[j]]--;
          if(M[s[j]]==0) kf--;
          if(kf<k) return;
          cout<<j<<" "; 
          j++;
      }
      return;
  }
  
    long long int substrCount (string s, int k) {
    	//code here.
    
    	int i=0, kc=k, n=s.size();
    	unordered_map <char, int> M;
    for(int i1=0;i1<n;i1++){
        if(M.find(s[i1])==M.end()) M[s[i1]]=1;
        else{
            auto it=M.find(s[i1]);
            (*it).second++;
        }
    }
    auto b=M.begin();
    while(b!=M.end()){
        cout<<(*b).first<<" "<<(*b).second;
        cout<<endl;
        b++;
    }
    cout<<" cccccccccc"<<M.size();
    for(int x=0;x<M.size();x++){
      
    }
    while(i<n){
        fun(s, i, kc, k, M, n);
        M[s[i]]--;
        if(M[s[i]]==0) kc--;
        if(kc<k) break;
        i++;
    }
    return ans;
    }

int main(){

    string a="aba";
    int k=2;
    cout<<substrCount(a,k);
    return 0;
}    