#include <iostream>
#include <array>
using namespace std;

bool valid(int a[]){
if(a[0]==0 && a[1]==0 && a[2]==0) return true;
return false;
}
int b[3]={10,5,1};

bool fun(int a[], int pos){
 if(valid(a)) return true;
 if(pos>2) pos=0;
 for(int i=0;i<3;i++){
   if(a[pos]-b[i]>=0) {
    a[pos]-=b[i];
    if(fun(a, pos+1)) return true;
    a[pos]+=b[i];}
 }
 return false;
}

int main(){
    int a[3]={16,16,16};
    if(fun(a,0)) cout<<"yes";
    else cout<<"no";
    return 0;
}