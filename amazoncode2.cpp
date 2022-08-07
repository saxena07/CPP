#include <bits/stdc++.h>
using namespace std;


long findmax(vector<int> v, int k){
    int n=v.size();
    long ans=0, ansutil=0;
    unordered_set<int> s;
    for(int i=0;i<k;i++){ s.insert(v[i]); ansutil+=v[i]; cout<<v[i]<<" "; }
    cout<<endl;
    if(s.size()==k) ans=max(ans, ansutil);
    int prev = v[0];
    for(int i=k;i<=n-1;i++){
        cout<<prev<<" "<<v[i]<<endl;
        ansutil=ansutil+v[i]-prev;
        for(auto it: s) cout<<it<<" ."; cout<<endl;
        s.erase(prev);
        s.insert(v[i]);
        if(s.size()==k) ans=max(ans, ansutil);
        prev=v[i-k+1];
    }
    return ans;
}

int main(){
    vector<int> v={1,2,7,7,4,3,6};
    int n=v.size();
    int k=3;
    cout<<findmax(v, k);

    // main()
    return 0;
}