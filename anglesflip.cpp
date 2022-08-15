#include <iostream>
#include <bits/stdc++.h>
#define isfind(M, num) (M.find(num)==M.end())

using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	while(n--){
        int n,m;
        cin>>n>>m;
        bool f=true;
        if(n==1 || m==1){
            vector<vector<int>> v1(n, vector<int> (m));
            vector<vector<int>> v2(n, vector<int> (m));
            for(int i=0;i<n;i++) {for(int j=0;j<m;j++){
                int h; cin>>h; v1[i][j]=h;
            }}
            for(int i=0;i<n;i++) {for(int j=0;j<m;j++){
                int h; cin>>h; v2[i][j]=h;
            }}
            for(int i=0;i<n;i++) {for(int j=0;j<m;j++){
                if(v1[i][j]!=v2[i][j]) {f=false; break;}
            }}
            
        }
        else {
            int num;
            map<int, int> a, b, c, d;
             for(int i=0;i<n;i++) {for(int j=0;j<m;j++){
                cin>>num;
                if((i+j)%2){
                    if(isfind(a, num)) a.insert({num,1});
                    else a.insert({num,a[num+1]});
                }
                else{
                      if(isfind(b, num)) b.insert({num,1});
                    else b.insert({num,b[num+1]});                    
                }
             }
        }        
         for(int i=0;i<n;i++) {for(int j=0;j<m;j++){
             cin>>num;
                if((i+j)%2){
                    if(isfind(c, num)) c.insert({num,1});
                    else c.insert({num,c[num+1]});
                }
                else{
                      if(isfind(d, num)) d.insert({num,1});
                    else d.insert({num,d[num+1]});                    
                }
         }
         }
         for(auto it:a){
            if(it.second!=c[it.first]){
                f=false; break;
            }
         }
         for(auto it:b){
            if(it.second!=d[it.first]){
                f=false; break;
            }
         }
         }

 if(f) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;












	    // int n, m;
	    // unordered_map<int, int> even;
	    // unordered_map<int, int> odd;
	    
	    // cin>>n>>m;
	    // vector<vector<int>> v1(n, vector<int> (m));
	    // for(int i=0;i<n;i++){
	    //     for(int j=0;j<m;j++){
	    //         int h; cin>>h;
	    //         if((i+j)%2) odd[h]++;
	    //         else even[h]++;
        //         v1[i][j]=h;
	    //     }
	    // }
        // // cout<<"odd : "; 
        // // for(auto it: odd) cout<<it<<" ";
        // // cout<<endl;
        // // cout<<"even : "; 
        // // for(auto it: even) cout<<it<<" ";
        // // cout<<endl;
	    // vector<vector<int>> v(n, vector<int> (m));
	    // bool f=true;
	    // for(int i=0;i<n;i++){
	    //     for(int j=0;j<m;j++){
	    //         int h;
	    //         cin>>h;
	    //         if(f){
	    //               if((i+j)%2){
        //                   if(v[i][j]==v1[i][j]) continue;
        //                   else if(odd.find(h)!=odd.end() && odd[h]>0) {continue; odd[h]--;}
        //                   else f=false;
        //                 }
	    //               else if((i+j)%2==0){
        //                   if(v[i][j]==v1[i][j]) continue;
        //                   else if(even.find(h)!=even.end() && even[h]>0) {continue; even[h]--;}
        //                   else f=false;
        //                 }
	    //               }
	    //         v[i][j]=h;
	    //     }
	    // }
	    // if(f) cout<<"YES"<<endl;
	    // else cout<<"NO"<<endl;
	}
	return 0;
}
