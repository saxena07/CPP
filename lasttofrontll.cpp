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

void lasttofront(node** head_ref){
    node* head= *head_ref;
    node* current= head;
    if(head->next==NULL){
        cout<<"Only one element present !!!!!!! "<<endl;
        return;
    }
    while(current->next->next!=NULL) current = current->next; 
    node* last=current->next;
    current->next=NULL;
    last->next=head;
    *head_ref=last;
    return;
}


void display(node* head){
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<" -> ";
        current= current->next;
    } cout<<endl;
}

int main(){
    node* head=new node(1);
    for(int i=2;i<11;i++) append(&head,i);
    display(head);
    lasttofront(&head);
    display(head);

    return 0;
}