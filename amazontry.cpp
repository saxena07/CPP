#include <bits/stdc++.h>
using namespace std;

int findminadditioon(string sw, string rw){
    int s1=sw.size(), s2=rw.size();
    int j=0;
    for(int i=0; i<s1; i++){
        if(sw[i]==rw[j]) j++;
        if(j==s2) return 0;
    }
    return s2-j;
}

int main(){
    string searchword="armaze";
    string resukltword="amazon";
    cout<<findminadditioon(searchword,resukltword);
    return 0;
}