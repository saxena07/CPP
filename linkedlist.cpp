#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    struct Node* next;
};
 void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    /* 2. put in the data */
    new_node->data = new_data;
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); // *head_ref is equal to &data (data of head node)
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node; //we made changes in head by this statement
}
/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }
 
    /* 2. allocate new node */
    Node* new_node = new Node();
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}
 
/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    Node *last = *head_ref; /* used in step 5*/
    /* 2. put in the data */
    new_node->data = new_data;
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;
    /* 4. If the Linked List is empty,
    then make the new node as head */
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

void deleteNodeatp(Node **head_ref, int position)
{
     
    // If linked list is empty
    if (*head_ref == NULL)
        return;
     
    // Store head node
    Node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0)
    {
         
        // Change head
        *head_ref = temp->next;
         
        // Free old head
        free(temp);            
        return;
    }
 
    // Find previous node of the node to be deleted
    for(int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
     Node *next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next); // Free memory
     
    // Unlink the deleted node from list
    temp->next = next;
}

// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; 
        delete temp;            
        return;
    }
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete temp;
    }
}

void deleteList(Node** head_ref)
{
 
    /* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}
 
int getCount(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
} 

void printmiddlenode(Node** head_ref)
{
    Node* temp = *head_ref;
    Node* temp2 = *head_ref;
    while(temp!=NULL && temp->next!=NULL)
    { 
      temp=temp->next->next;  
      temp2=temp2->next;
    }
    std::cout<<"\nYour Middle element is :"<<temp2->data;
    return;
}

void countkey(Node* n,int key)
{int count=0;
  while (n!=NULL)
  {
    if(n->data == key){
     count++;
    }
     n = n->next;
  }
 std::cout<< "\nelement "<<key<<" has occured " <<count <<" times.";
}
/*
void removeduplicates(Node** head_ref)
{   int i=0;
    Node* temp = *head_ref;
    Node* temp1 = *head_ref;
    Node* temp2 = *head_ref;
    while(temp1!=NULL)
    {i=0;
    while(temp2!=NULL)
    {
     if(temp2->data == temp1->data)
       {
       deleteNodeatp(&temp,i);
       }
       temp2=temp2->next;
       i=i+1;
    }
    temp1=temp1->next;
    }
    cout<<"\nDuplicates removed";
}
*/
// This function prints contents of
// linked list starting from head
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{   using std::cout;
    using std::cin;
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    
    append(&head,1);

    printList(head);   
    return 0;
}









/*
 bool isPalindrome(Node *head)
    { int s=0;
    Node* i1=head,* next=NULL,* forw;
    while(i1->next!=NULL) {s++; i1=i1->next;}
    s=(s-1)/2;
    Node* curr=head;

    while(s>=0){
        forw=curr->next;
        curr->next=next;
        next=curr;
        curr=forw;
        s--;
    }head->next=curr;
    while(curr!=NULL){
        if(curr!=next) return 0;
        curr=curr->next;
        next=next->next;
    }return 1;
        
    }
*/