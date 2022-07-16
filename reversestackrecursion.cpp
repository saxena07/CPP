#include<iostream>
#include<stack>
using namespace std;

stack<int> s;


void insertatbottom(int x){
    if(s.empty()){s.push(x);
    return;}
    int curr=s.top();
    s.pop();
    insertatbottom(x);
    s.push(curr);
    return;
}

void stackreverse(){
    if(s.empty()) return;
    int curr=s.top();
    s.pop();
    stackreverse();
    insertatbottom(curr);
    return;
}

void priint(){
    while(!s.empty()){
        int c=s.top();
        s.pop();
        cout<<c<<" ";
    }
    cout<<endl;
}

int main(){
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    priint();
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    stackreverse();
    priint();
    return 0;
}
