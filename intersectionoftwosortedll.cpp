#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* next;
Node(int d){
  this->data=d;
  this->next=NULL;
}
};

void append(Node** head_ref, int new_data)
{
    /* 1. allocate Node */
    Node* new_Node = new Node(new_data);
    Node *last = *head_ref; 
    if (*head_ref == NULL)
    {
        *head_ref = new_Node;
        return;
    }
    /* 5. Else traverse till the last Node */  
    while (last->next != NULL)
        last = last->next;
    /* 6. Change the next of last Node */
    last->next = new_Node;
    return;
}
Node* findIntersection(Node* head1, Node* head2)
{
    Node* H=new Node(0);
    Node* curr=H;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data) head1=head1->next;
        else if(head2->data<head1->data) head2=head2->next;
        else if(head1->data==head2->data) {
            H->next=new Node(head1->data);
            H=H->next;
            head1=head1->next;
            head2=head2->next;
        }
    }
    
        return curr->next;
}

void print(Node* head){
    Node* current=head;
    while(current!=NULL){
        cout<<current->data<<" -> ";
        current= current->next;
    } cout<<endl;
}


int main(){
    Node* head1=new Node(1),* head2=new Node(2);
    for (int i = 2; i < 5; i++)
    {
     append(&head1,i); append(&head2,i*2);
    }
    cout<<" List 1 : ";print(head2); cout<<endl;
    cout<<" List 2 : ";print(head1); cout<<endl;
    Node * head=findIntersection(head1,head2);
    cout<<" Intersection of both lists : ";print(head); cout<<endl;

    return 0;
}