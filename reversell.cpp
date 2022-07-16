#include<iostream>
using namespace std;

class node{
public:
int data;
node* next;
node(int d){
  this->data=d;
  this->next=NULL;
}
};

void append(node** head_ref, int new_data)
{
    /* 1. allocate node */
    node* new_node = new node(new_data);
    node *last = *head_ref; 
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    /* 5. Else traverse till the last node */  
    while (last->next != NULL)
        last = last->next;
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void RecursiveReverse(node**head_ref,node* head, node* prev){
    
    if(!head) {
    *head_ref = prev; 
    return;
    }

    node* nextnode=head->next;
    head->next=prev;
    prev=head;
    RecursiveReverse(head_ref,nextnode,prev);
    
    return;
}

void reverse(node** head_ref){
   node* current=* head_ref;
   node* temp=NULL,*t;
   if(current==NULL) {cout<<"EMPTY LIST"; return;}
   while(current!=NULL){
      t=current->next;
      current->next=temp;
      temp=current;
      current=t;
   } *head_ref=temp;
   
 return;
}



void print(node* head){
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<" -> ";
        current= current->next;
    } cout<<endl;
}

int main(){
    node* head=new node(1);
    for(int i=2;i<11;i++) append(&head,i);
    print(head);
    RecursiveReverse(&head,head,NULL);
    print(head);
    return 0;
}