#include<iostream>
using namespace std;

string nearestPalindromic(string n) {
       
        if(n.length()==1){
            int a=n[0]-48;
            if(a==0) return "0";
            string s(1,a+47);
            return s;
        }

        int size = n.length()-1;
        string x(size+1, 'a'),y;
        for (int i = 0; i <= size/2; i++)
        {
          x[i]=n[i];
          x[size-i]=n[i];
        }
        return x;
        
    }

int main(){
   string a;
   cin>>a;
   cout<<nearestPalindromic(a);

    return 0;
}