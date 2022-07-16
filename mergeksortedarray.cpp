#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> v;
        // priority_queue<pair<int, int> ,vector<pair<int, int>> , greater<int> > m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > m;
        vector<int> it(arr.size(), 0);
        
        for(int i=0;i<arr.size();i++) m.push(make_pair(arr[i][it[i]] , i));
        while(!m.empty()){
            pair<int, int> p=m.top();
            m.pop();
            v.push_back(p.first);
            it[p.second]++;
            if(it[p.second]<arr[0].size()) m.push( make_pair( arr[p.second][it[p.second]] , p.second ));
        }
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout <<endl;
    return v;
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    mergeKArrays(arr, 3);
    return 0;
}