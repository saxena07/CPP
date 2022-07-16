#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> v(1000);
int TOP=-1;
int minele=INT_MAX;
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

void push(int ele){
    if(TOP>=1000) {
        cout<<"stack overflow";
        return;
    }
    cout<<"element pushed "<<ele<<endl;
if(TOP==-1){
v[++TOP]=ele;
minele=ele;
}
else if(ele>=minele){
    v[++TOP]=ele;
}else if(ele<minele){
    v[++TOP]=(2*ele)-minele;
    minele=ele;
}
return; 
}

void pop(){
    if(TOP<=-1){
        cout<<"empty stack"; return;
    }
    cout<<v[TOP]<<" popped"<<endl;
    if(v[TOP]>=minele){
        --TOP;
    } 
    else{
       minele=(2*minele)-v[TOP];
       --TOP;
    }
    return;
}

void showstack(){
    cout<<"Your Stack : ";
    for (int i = 0; i <= TOP; i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}

int minelement(){
    cout<<"Min element in stack : ";
    return minele;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    push(3);
    push(5);
    // showstack();
    cout<<minelement()<<endl;
    push(2);
    push(1);
    cout<<minelement()<<endl;
    // showstack();
    pop();
    // showstack();
    cout<<minelement()<<endl;
    pop();
    // showstack();
    cout<<v[TOP]<<endl;

    

    return 0;
}