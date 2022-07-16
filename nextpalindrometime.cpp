#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int fun(string s){
int a=s[0]-'0';
int b=s[1]-'0';
int c=s[3]-'0';
int d=s[4]-'0';
int h=(a*10)+b;
int m=(c*10)+d;
vector<pair<int, int>> v={{00,00},{01,10},{02,20},{03,30},{04,40},{05,50},{10,01},{11,11},{12,21},{13,31},{14,41},{15,51},{20,02},{21,12},{22,22},{23,32} };
int in=v.size()-1;
for(int i=0;i<v.size()-1;i++) {
 
if(h<v[i].first){
    in=i;
    break;
    }   
else if(h==v[i].first) {
    if(m==v[i].second) return 0;
    else if(m>v[i].second) { in=i+1; break;}
    else {in =i;  break;}
    } 

}
cout<<in<<endl;
if(in==15){
    return ((23-h)*60)+(60-m);
}
int md=v[in].second-m;
int hd=v[in].first-h;
int ans=(hd*60)+md;
return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s="13:32";
    cout << fun(s)<<" minutes";
    return 0;
}