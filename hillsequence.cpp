#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int printanswer(vector<int> a){
sort(a.begin(), a.end());
for (int i = a.size()-1; i >=0; i--)
{  if(i-1>=0){
     if(a[i]==a[i-1]){
                            if(i-2>=0){
                            if(a[i-2]==a[i]){
                             return -1;  }}
      int t=a[i];
      a[i]=0;
      a.push_back(t);   
     }
 }
}
 for (int i = a.size()-1; i>=0; i--) if(a[i]!=0) cout<<a[i]<<" ";
 cout<<endl;
 return 0;
}

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {   int size;
        cin>>size;
        vector<int> a(size);
        for (int i = 0; i < size; i++) cin>>a[i];
        if(printanswer(a)==-1) cout<<-1<<endl;
    }
    
	return 0;
}
