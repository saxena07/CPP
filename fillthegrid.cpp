#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int count;
cin>>count;
while(count-->0){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> q(m);
    set<int> s, s1;
    for(int i=0;i<n;i++) s.insert(i+1);
    for(int i=0;i<m;i++) {
    cin>>q[i].first>>q[i].second;
    s1.insert(q[i].first);
    }
    vector<int> v(n, -1);
    bool f=0;
    for(int i=0;i<m;i++){
        f=0;
        for(int j=q[i].second-1;j>=0;j--){
            if(v[j]==-1){
                auto it=s.find(q[i].first);
                s.erase(it);
                v[j]=q[i].first; 
                f=1; 
                break;
            }
        }
        if(!f) break;
    }
    if(!f) {cout<<-1<<endl; continue;}
    
    auto it1=s1.begin();
    for(int i=0;i<m;i++, it1++){
        bool f=0;
        if(q[i].first<q[i].second){
        for(int j=(*it1)-1;j<q[i].second-1;j++){
            
            if(v[j]==-1){
                v[j]=(*it1);
                f=1;
                break;
            }
        }
        if(f) v[q[i].second-1]=-1; }
    }

    auto it=s.begin();
    for(int i=0;i<n;i++){
        if(v[i]==-1) {v[i]=(*it); it++;}
    }
    
    for(int i=0;i<n;i++) cout<<v[i]<<" "; cout<<endl;
}
return 0;
}