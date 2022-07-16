//                                      DONE IN LEETCODE
#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3= new ListNode(),*L1=l1,*L2=l2;
        int r=0;
         l3->val=L1->val + L2->val;
            if(l3->val>9) {r=1; l3->val%=10;}
            else r=0;
         L1=L1->next; L2=L2->next;
        
        while(L1!=NULL && L2!=NULL){
            int n=L1->val + L2->val + r;
            if(n>9) {r=1; n=n%10;}
            else r=0;
           
           l3->next=new ListNode(n);
           l3=l3->next; 
           L1=L1->next; L2=L2->next;
        }
        if(L1==NULL && L2!= NULL){
            while(L2!=NULL){
               int n=L2->val+r;
            if(n>9) {r=1; n%=10;}
            else r=0;
                l3->next=new ListNode(n);
                l3=l3->next;
                L2=L2->next;
            }
            
        }
        else if(L2==NULL && L1!=NULL){
            while(L1!=NULL){
               int n=L1->val+r;
            if(n>9) {r=1; n%=10;}
            else r=0;
                l3->next=new ListNode(n);
                l3=l3->next;
                L1=L1->next;
            }
        }
        if(r!=0) l3->next=new ListNode(r);
        return l3;
    }

int main(){
    ListNode* L1=new ListNode(),*l2=new ListNode();
    L1->val=1;

    ListNode* l3=addTwoNumbers(L1,l2);


    return 0;
}