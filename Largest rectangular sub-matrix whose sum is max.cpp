#include<bits/stdc++.h>
using namespace std;


vector<int> kadane(vector<int> v, int m){
    int ci=0,cj=0, ciutil=0;
    int maxsumutil=0, maxsum=0;
    // for(int i=0;i<m;i++) cout<<v[i]<<" ";  cout<<endl;
    for (int i = 0; i < m; i++)
    {maxsumutil+=v[i];
    if(maxsum<maxsumutil){
        maxsum=maxsumutil;
        cj=i;
        ci=ciutil;
    }
    if(maxsumutil<0){
        maxsumutil=0;
        ciutil=i+1;
    }
    }
    // if(maxsum==29) for(int i=0;i<m;i++) cout<<v[i]<<" "; 
    return {ci, cj, maxsum};
}  
  
vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
    int n=a.size(), m=a[0].size();
    int ri=0,rj=0,ci=0,cj=0;
    int maxsum=0;
    for(int i=0;i<n;i++){
        vector<int> rowutil(m, 0);
        for(int j=i;j<n;j++){

            for(int k=0;k<m;k++) rowutil[k]+=a[j][k];
            vector<int> ansutil=kadane(rowutil, m);
            if(ansutil[2]>maxsum){
                maxsum=ansutil[2];
                ci=ansutil[0];
                cj=ansutil[1];
                ri=i;
                rj=j;
                // if(maxsum==29) cout<<ri<<" "<<rj<<" "<<ci<<" "<<cj<<endl;
            }

        }
    }
    cout<<maxsum<<endl;
    vector<vector<int>> ans(rj-ri+1, vector<int> (cj-ci+1));

    for(int i=ri;i<=rj;i++){
        for(int j=ci;j<=cj;j++){
            // ans[i][j]=a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return ans;
  }

int main(){
    vector<vector<int>> a={ { 1, -1, 2, 8, -20 },
						{ -8, 2, 4, 2, 1 },
						{ 3, 8, 1,8, 3 },
						{ -4, -1, 1, 9, -1 } };
    vector<vector<int>> ans=sumZeroMatrix(a);
    // for(int i=0;i<ans.size();i++){for(int j=0;j<ans[0].size();j++){ cout<<ans[i][j];} cout<<endl;}
    return 0;
}