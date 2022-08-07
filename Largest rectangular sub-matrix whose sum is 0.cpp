#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:

vector<int> kadane(vector<int> v, int m){
    int ci=-1,cj=-1, ciutil=-1;
    int maxsumutil=0, maxsum=0;
    for (int i = 0; i < m; i++)
    {maxsumutil+=v[i];
    if(maxsumutil==0 && cj-ci>i-ciutil){
        maxsum=maxsumutil;
        cj=i;
        ci=ciutil;
    }
    if(maxsumutil==0){
        maxsumutil=0;
        ciutil=i;
    }
    }
    return {ci, cj, maxsum};
}  
  
vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
    int n=a.size(), m=a[0].size();
    int ri=0,rj=0,ci=0,cj=0;
    int maxsum=-1;
    for(int i=0;i<n;i++){
        vector<int> rowutil(m, 0);
        for(int j=i;j<n;j++){

            for(int k=0;k<m;k++) rowutil[k]+=a[j][k];
            vector<int> ansutil=kadane(rowutil, m);
            if(ansutil[2]==0){
                maxsum=0;
                if(ri==0 && rj==0 && cj==0 && ci==0){
                ci=ansutil[0];
                cj=ansutil[1];
                ri=i;
                rj=j;
                }
                else if((ansutil[1]-ansutil[0]+1)*(j-i+1)>(rj-ri+1)*(cj-ci+1)){
                ci=ansutil[0];
                cj=ansutil[1];
                ri=i;
                rj=j;
                }
            }

        }
    }
    if(maxsum==-1) return {{-1}};
    vector<vector<int>> ans(rj-ri+1, vector<int> (cj-ci+1));
    for(int i=ri;i<=rj;i++){
        for(int j=ci;j<=cj;j++){
            ans[i][j]=a[i][j];
        }
    }

    return ans;
  }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}