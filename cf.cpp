#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

int cf(vector<int> v, int start ,int end, vector<vector<int>> m){
if(start>end) return INT_MAX;
if(start==end) return m[start][end]=v[start];
if(m[start][end]!=-1) return m[start][end];
for (int i = start+1; i <= end; i++)
{
 int t=v[start];
 v[start]=v[i];
 v[i]=t;   
 m[start][end]=min(m[start][end], cf(v, start, end -1, m));   
}
return m[start][end];
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {   
    vector<int> v;
    string c;
    cin>>c;
    for(int j=0;j<c.size(); j++) v.push_back(c[j] - '0');
    // int r=INT_MAX;
    vector<vector<int>> m(c.size(), vector<int> (c.size(), -1));
    for (int k = 0; k < c.size(); k++) {m[0][k]=v[k];
    m[k][0]=v[k];}
    cout<<cf(v, 0, v.size()-1, m)<<endl;
    v.clear();
    }
    
    return 0;
}