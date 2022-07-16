#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int als(int a[4][4], int t[4][4], int * e, int * x){
vector<vector<int>> v(4,vector<int> (4));
a[0][0]+=e[0];
a[1][0]+=e[1];
a[0][3]+=x[0];
a[1][3]+=x[1];

v[0][0]=a[0][0];
v[1][0]=a[1][0];

for(int i=1;i<4;i++){
v[0][i]=min(v[0][i-1]+a[0][i],v[1][i-1]+t[1][i]+a[0][i]);
v[1][i]=min(v[1][i-1]+a[1][i],v[0][i-1]+t[0][i]+a[1][i]);
}

return min(v[0][3],v[1][3]);
}

int main() 
{ 
   int a[][4] = {{1,7,6,3},
							{8,3,2,2}};
	int t[][4] = {{0, 7, 5, 9},
							{0, 0,2,10}};
	int e[] = {8,9}, x[] = {5,3};
  
    cout << als(a, t, e, x); 
  
    return 0; 
} 
  