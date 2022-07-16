#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

 string findMaximumNum(string str, int k)
    {
       vector<int> v;
       int a;
       for(int i=0;i<str.size();i++){
         a=str[i]-'0';
        //  cout<<a<<" ";
         v.push_back(a);
       }
       auto b=v.begin();
       for(int i=0;i<k;i++){
       auto it=max_element(b, v.end());
       auto d=b++;
    //    if(it<=d) break;
    //    cout<<*it<<"  "<<*b<<endl;
    if(it==d) i--;
        auto c=*it;
        *it=*d;
        *d=c;
        // cout<<*d<<" "<<endl;
       }
       for(int i=0;i<str.size();i++){
           str[i]=v[i]+'0';
       }
       return str;
    }

int main(){
    string b=findMaximumNum("4551711527", 3);
    cout<<b<<endl;

    return 0;
}