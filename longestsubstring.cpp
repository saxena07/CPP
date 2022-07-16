#include<iostream>
#include<stack>
using namespace std;

int findMaxLen(string s) {
        stack<int> p;
        int f=-1;
        p.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {p.push(i); f=1;}
            else{
                if(s[p.top()]=='(') {p.pop(); f=0;}
                else {p.push(i); f=1;}
            }
        }
        if(f==0) p.push(s.size());
        int m=0;
        while(!s.empty()){
            int curr=p.top();
            if(curr==-1) break;
            p.pop();
            m=max(m,curr-p.top()-1);
        }
        return m;
    }

int main(){

    cout<<findMaxLen("()()()()()()()()()()()()()()()()");
    return 0;
}    