#include<iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

struct queu
  {
    stack<int> stk1, stk2;

   void enqueue(int x){
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
            }
            stk1.push(x);
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }    
    }
   int dequeue(){
             if (stk1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }

       int a = stk1.top();
       stk1.pop(); 
       return a;
   }
};



int main()
{   queu q;
    for (int i = 0; i < 10; i++)
    {
      q.enqueue(i+1);
    }
    cout<<"\n";
    cout<<"Your queue : ";
    for (int i = 0; i < 10; i++)
    {
        cout<<q.dequeue();
    }
    

return 0;
}