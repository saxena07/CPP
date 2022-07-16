#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(long long j){
     if (ceil((double)sqrt(j)) == floor((double)sqrt(j))) return 1;
     return 0;
}

int main(){
int count;
cin>>count;

while(count-->0){

long long N;
cin>>N;

if(N%2!=0) {cout<<0<<endl; continue;}

long long sqrtn=sqrt(N);
vector<pair<long long, long long>> vp;

for (long long i = 0; i <= sqrtn+1/2; i++)
{ long long j=N- (i*i);
if(check(j)) {long long j1=sqrt(j); vp.push_back(make_pair(min(i,j1), max(i,j1)));}
}

int ans=0;

for(int i=0;i<vp.size()/2;i++){
long long a, b, g, l;
for(b=1;b<=vp[i].second;b++){
    // cout<<a;
    a=vp[i].first+b;
    g=__gcd(a,b);
    l=(a*b)/g;
    if(g+l==vp[i].second){
        if(a==b) ans+=1;
        else ans+=2;
    }
}

}
cout<<ans<<endl;
}
    return 0;
}