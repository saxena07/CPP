#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    int height;
};
 
int height(Node *N){
    if (N == NULL) return 0;
    return N->height;
}
 
int max(int a, int b)
{ return (a > b)? a : b; } 
 

Node* newNode(int data)
{   Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}
 

Node *rightRotate(Node *y)
{   Node *x = y->left;
    Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
 
    return x;
}
 


Node *leftRotate(Node *x)
{   Node *y = x->right;
    Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
 
    return y;
}
 

int getBalance(Node *N)
{
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}



Node* insert(Node* node, int data)
{

    if (node == NULL)
        return(newNode(data));
 
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else 
        return node;
 

    node->height = 1 + max(height(node->left),
                        height(node->right));


    int balance = getBalance(node);
 
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
   
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
 
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
  
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 

    return node;
}

Node * minValueNode(Node* node)
{
    Node* current = node;

    while (current->left != NULL)
        current = current->left;
 
    return current;
}

Node* deleteNode(Node* root, int data)
{
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
    if ( data < root->data )
        root->left = deleteNode(root->left, data);
 
    else if( data > root->data )
        root->right = deleteNode(root->right, data);
 
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ?
                         root->left :
                         root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; 

            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);
 
            root->data = temp->data;
 

            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }
 

    if (root == NULL)
    return root;
 

    root->height = 1 + max(height(root->left),
                           height(root->right));
 

    int balance = getBalance(root);
 
    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 
 

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
    return 0;
}