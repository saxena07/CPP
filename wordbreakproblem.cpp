#include<iostream>
#include<vector>
using namespace std;

 vector<string> ans;
    bool isthere(string a,vector<string> &dict){
        int s= dict.size();
        for(int i=0;i<s;i++){
            if(dict[i].compare(a)==0) return true;
        }
        return false;
    }
    
    void wordbreakutil(int q, vector<string>& dict, string s, string result)
    {
   
      for(int i=1;i<=q;i++){
        
        string a = s.substr(0,i);
        if(isthere(a,dict)){
            if(i==q){
                result+=a;
                ans.push_back(result);
                cout<<result<<" "<<endl;
                return;
        }
         wordbreakutil(q-i,dict,s.substr(i,q-i),result+a+" ");
      }    
    }
    }
    
vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
     wordbreakutil(s.size(),dict,s,"");
     return ans;
    }

int main(){
   string a="catsanddog";
   vector<string> v={"cat", "cats", "and", "sand", "dog"};
   wordBreak(5,v,a);
    return 0;
}