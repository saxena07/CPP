#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
 int data;
Node* left;
Node* right;

 Node(int val){
     data=val;
     left=NULL;
     right=NULL;
 }
};


/* Function to insert element in binary tree */
Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = new Node(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = new Node(data);
            return root;
        }
    }
}

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    cout << node->data << " ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    cout << node->data << " ";
 
    /* then recur on left sutree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}

queue<Node*> Q;
void printlevelorder(Node* root)
{
 if(root!=NULL){
 cout<<root->data;
 if(root->left !=NULL){
     Q.push(root->left);
     }
 if(root->right !=NULL){
     Q.push(root->right);
     }
     if(!Q.empty())
     {
   Node* temp = Q.front();
   Q.pop();
  printlevelorder(temp);
     }
 }
}

int main(){

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  //enter(root,2);

  cout<<"Level order Traversal : ";
  printlevelorder(root);
  cout<<endl;
    
    return 0;
}