#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    char data;
    Node *left, *right;
};

Node* newNode(char data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

pair<int, int> findindex(string s, int i){
    int N=s.size();
    if(i==N || s[i]==')') return make_pair(-1, -1);
    pair<int, int> p;
    if(s[i]=='(') p.first=i;
    stack<int> st; st.push(i);
    i++;
    int in=i;
    while(!st.empty()){
        if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            in=i;
            st.pop();
        }
        i++;
    }
    p.second=in;
    return p;
}

Node* constree(int i, string s){
    Node* root=newNode(s[i]);
    
    pair<int, int> L=findindex(s, i+1);
    if(L.first==-1 && L.second==-1) return root;
    else root->left=constree(L.first+1, s.substr(L.first+1 , L.second-L.first-1));
    
    pair<int, int> R=findindex(s, L.second+1);
    if(R.first==-1 && R.second==-1) return root;
    else root->right=constree(R.first+1, s.substr(R.first+1 , R.second-R.first-1));
    
    return root;
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
	//code
	string s="4(2(3)(1))(6(5))";
	Node* root=constree(0, s);
	preOrder(root);
	return 0;
}