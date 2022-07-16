#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int Eno;
    float marks;
    int rank;
    string name;

    Node* left;
    Node* right;

    Node(int a,float b, int c, string d){
        Eno=a;
        marks=b;
        rank=c;
        name=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void kthstudent(Node* root,int Rank){
   if(root==NULL) {cout<<" EMPTY TREE !"<<endl; return;}
    Node* curr=root;

    while(1)
    {
    if(curr==NULL) {cout<<" Rank not found !"<<endl;
    return;}
    if(Rank==curr->rank){
        cout<<"Eno. : "<<curr->Eno<<endl;
        cout<<"Name : "<<curr->name<<endl;
        cout<<"marks : "<<curr->marks<<endl;
        cout<<"Rank : "<<curr->rank<<endl;
        return;
    }
    else if(Rank<curr->rank)  curr=curr->left;
    else curr=curr->right;
    }
    
  return;
}

int main(){

    return 0;
}