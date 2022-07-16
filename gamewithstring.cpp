#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int minValue(string s, int k){
        sort(s.begin(), s.end());
           vector<int >v;
       v.push_back(1);
       int temp=0;
       for(int i=1;i<s.size();i++)
       {
           if(s[i]==s[i-1])
           {
               v[temp]+=1;
               
           }
           else
           {
               v.push_back(1);temp++;
           }
       }
        for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout<<endl;
      priority_queue<int> maxi;
        for(int j=0;j<v.size();j++) maxi.push(v[j]);
        while(--k &&maxi.size()!=0){
            int l=maxi.top(); 
            cout<<l<<" h";
            maxi.pop();
            --l;
            // cout<<l<<" ";
            maxi.push(l); 
        }cout<<endl;
        int ans=0;
        while(!maxi.empty()){
            int y=maxi.top();
            ans+=(y*y);
            maxi.pop();
        }
        return ans;
    //     unordered_map<char,int> mp;
    //     int ans=0;
    //     for(auto it:s)
    //     mp[it]++;
    //      priority_queue<int > pq;
    //     for(char i='a';i<='z';i++){
    //    if(mp[i]!=0)
    //    pq.push(mp[i]);
    //     }
    //     while(!pq.empty()){
    //         int t=pq.top();
    //         pq.pop();
    //         if(k>0){
    //         ans+=(t-1)*(t-1);
    //         k--;
    //         }
    //         else
    //         ans+=t*t;
            
    //     }
    //     return ans;
    }
    

int main(){
    cout<<minValue("abccc", 1);
        return 0;
}