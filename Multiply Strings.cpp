#include<iostream>
#include<math.h>
using namespace std;


string multiply(string num1, string num2) {
  int i=num1.length()-1,j=0;
  unsigned long long n1=0;
  while(i>=0){
      n1 += pow(10,j++)*((unsigned long long)num1[i--]-48);
  }
  int k=num2.length()-1,l=0;
  unsigned long long n2=0;
  while(k>=0){
      n2 += pow(10,l++)*((unsigned long long)num2[k--]-48);
  }
  unsigned long long n3=n1*n2;
  string num3;
  int w=0;
  while(n3>=0){
      unsigned long long q=n3%10;
      char a= q+48;
      cout<<a<<" "<<q;
      num3[w++]=a;
      n3/=10;
  }
  return num3;
}

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    cout<<multiply(a,b);
    return 0;
}