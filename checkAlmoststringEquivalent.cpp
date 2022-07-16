#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  
  
 bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map <char,int> s1,s2;
        for(int i=0;i<word1.size();i++) {
            if(s1.find(word1[i])!=s1.end()){
                auto it=s1.find(word1[i]);
                (*it).second++;
            }
            else s1.insert({word1[i],1});}

        for(int i=0;i<word2.size();i++) {
            if(s2.find(word2[i])!=s2.end()){
                auto it=s2.find(word2[i]);
                (*it).second++;
            }
            else s2.insert({word2[i],1});}
      
        for(auto it:s1){
            int c;
            auto it2=s2.find(it.first);
            if(s2.find(it.first)!=s2.end()) c=(*it2).second;
            else c=0;
            if(abs(it.second-c)>3) return 0;
        }
        for(auto it:s2){
            int c;
            auto it1=s1.find(it.first);
            if(s1.find(it.first)!=s1.end()) c=(*it1).second;
            else c=0;
            if(abs(it.second-c)>3) return 0;
        }
        return 1;
 }           

int main(){
  string s1="cccddabba",s2="babababab";
  cout<<checkAlmostEquivalent(s1,s2);
    return 0;
}    