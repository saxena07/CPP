
#include<bits/stdc++.h>
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

void insert(node** head_ref, int n){
    node* new_node = new node();
    new_node->data = n;
    node* head = *head_ref;

   if(*head_ref == NULL){
       *head_ref = new_node;
       return;
   }
   
    if(n == head->data){
      return;
    }
    else if(n < head->data){
      insert(&head->left,n);
    }
    else if(n > head->data){
      insert(&head->right,n);
    }
}


void printInorder(node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
 

queue<node*> Q;
void printlevelorder(node* root)
{
 if(root!=NULL){
 cout<<root->data<<" ";
 if(root->left !=NULL) Q.push(root->left);
 if(root->right !=NULL) Q.push(root->right);
     if(!Q.empty())
 {
   node* temp = Q.front();
   Q.pop();
   printlevelorder(temp);
 }
 }
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int primefactorsum(int m1, int m2, node* root){
queue<node*> Q1;
int sum=0;
Q1.push(root);
node* curr=root;
while(!Q1.empty()){
    if(curr->left) Q1.push(curr->left);
    if(curr->right) Q1.push(curr->right);
    curr=Q1.front(); Q1.pop();
    if(isPrime(curr->data)==1){ 
      if(curr->data<=m2 && curr->data>=m1){
        sum = sum + curr->data;}   
        }
        }
return sum;
}


int main(){
    int a[10]={10,20,30,40,50,60,70,80,90,100};
    node* head=NULL;
       for (int i = 0; i < 10; i++){
        for(int j=1; j <= a[i]; j++){
         if (a[i] % j == 0){ 
          insert(&head,j);}}}
    printInorder(head);

    int m1,m2;
    cout<<endl;
    cout<<" Enter m1 and m2 : ";
    cin>>m1;
    cin>>m2;
    cout<<"SUM : "<<primefactorsum(m1,m2,head);
    
    return 0;
}