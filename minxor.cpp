#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	while(n--){
        long long n, x, y;
        cin>>n>>x>>y;
        vector<int> v(n);
        for(int i=0; i<n; i++){int h; cin>>h; v[i]=h;}

        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<n; i++) q.push(v[i]);
        while(y>0){
            int mini=q.top();
            if((mini^x)>mini){
                q.pop(); q.push(mini^x); y--;
            } else break;
        }
        if(y%2){
            int mini=q.top();q.pop();
            q.push(mini^x);
        }
        while(q.size()){cout<<q.top()<<' '; q.pop();} cout<<endl;
    }

    return 0;
}