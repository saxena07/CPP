#include<bits/stdc++.h>
using namespace std;

int Maximize(int a[],int n){
sort(a,a+n);
int m=1000000007,sum=0;
for (int i = 0; i < n; i++)
{
    sum=sum + a[i]*i;
}

return sum%m;

}

int main(){
 
 long long n=5;
 int a[]={5,3,4,1,2};
 
  cout<<Maximize(a,n);


    return 0;
}