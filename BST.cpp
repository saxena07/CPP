#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class node{
    public:
    int data;

    node* left;
    node* right;

    node(){
        this->left=NULL;
        this->right=NULL;
    }
};

int height(node* head){
    if(head==NULL) return 0;
    return 1 + max(height(head->left), height(head->right)); 
}

node* smallestnode(node* current){
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

node* largestnode(node* current){
    while(current->right!=NULL){
        current=current->right;
    }
    return current;
}

void swap(node* a, node* b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


void Deletenode(node* head, int data){
    node* n= head;

    if(data==n->data){
        
        if(n->right!=NULL){
            node* b = smallestnode(n->right);
            swap(n,b);
            Deletenode(smallestnode(n->right),b->data);
    }
    else if(n->left!=NULL){
        node* b = largestnode(n->left);
        swap(n,b);
         Deletenode(largestnode(n->left),b->data);
    }
    else{
     n->data=-1;
    }
}
   else if(data>n->data){
       Deletenode(n->right,data);
   }
   else{
       Deletenode(n->left,data);
   }

}




node* minValueNode(node* n)
{
    node* current = n;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}


node* deleteNode( node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        if (root->left==NULL and root->right==NULL)
            return NULL;
        else if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);

    }
    return root;
}


void insert(node** head_ref, int n){
    node* new_node = new node();
    new_node->data = n;
    node* head = *head_ref;

   if(*head_ref == NULL){
       *head_ref = new_node;
       return;
   }
   else{
    if(n <= head->data){
      insert(&head->left,n);
    }
    else if(n > head->data){
      insert(&head->right,n);
    }

}
}


queue<node*> Q;
void printlevelorder(node* root)
{
 if(root!=NULL){
 cout<<root->data<<" ";
 if(root->left !=NULL){
     Q.push(root->left);
     }
 if(root->right !=NULL){
     Q.push(root->right);
     }
     if(!Q.empty())
     {
   node* temp = Q.front();
   Q.pop();
  printlevelorder(temp);
     }
 }
}

void zigzaglevelorder(node* root){
    stack<node *> so,se;
    node* curr=root;
    se.push(curr);
    int mode=0;
    while(!se.empty() || !so.empty()){
    if(mode==0){
        while(!se.empty()){
        curr=se.top(); se.pop();
        cout<<curr->data<<" ";
        if(curr->left) so.push(curr->left);
        if(curr->right) so.push(curr->right);
    }
    mode=1;
    }
    else{
         while(!so.empty()){
        curr=so.top(); so.pop();
        cout<<curr->data<<" ";
        if(curr->right) se.push(curr->right);
        if(curr->left) se.push(curr->left);
    }
    mode=0;
    }
    }
}





int main(){
    node* head=NULL;
    
    int a[]={10,5,15,2,8,12,18,1,3,7,9,11,13,16,19};
    for (int i = 0; i < 15; i++) insert(&head,a[i]);
    printlevelorder(head);
    cout<<endl;
    zigzaglevelorder(head);
    return 0;
}