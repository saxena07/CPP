#include <iostream>
using namespace std;

int flipcomp(string a){
    int cz=0,co=0,fz=0,fo=0,n=a.size();
    if(n==1) return 0;
    if(n==2 && a[0]==a[1]) return 0; 
    else if(n==2 && a[0]!=a[1]) return 1;
    for (int i = 0; i < n; i++)
    { 
    if(a[i]=='0'){
      fz++; cz++; co=0;
      if(i+1<n) if(a[i+1]=='0') fz++;
      while(i<n && a[i+1]!='1') i++;
    }
     else if(a[i]=='1'){
      cz=0; co++; fo++;
      if(i+1<n) if(a[i+1]=='1') fo++;
      while(i<n && a[i+1]!='0') i++;
     }
    }
    return min(fz,fo);
}

int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {string a;
    cin>>a;
    cout<<flipcomp(a)<<endl;
    }    	
	return 0;
}

