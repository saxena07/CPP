#include<iostream>
using namespace std;


int main(){
  unsigned long long n, k,s;
  cin>>n;
  cin>>k;
  unsigned long long o;
  if(n%2!=0) o=(n/2)+1;
  else o=n/2;
  if(k==o) cout<< (o*2)-1;
  else if(k>o) cout<< (k-o)*2;
  else cout<< (k*2)-1;
  return 0;
}