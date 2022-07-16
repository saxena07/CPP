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
    // cout<<s<<endl;
    Node* root=newNode(s[i]);
    // cout<<root->data<<" ";
    pair<int, int> L=findindex(s, i+1);
    if(L.first==-1 && L.second==-1) return root;
    else root->left=constree(0 , s.substr(L.first+1 , L.second-L.first-1));
    
    pair<int, int> R=findindex(s, L.second+1);
    if(R.first==-1 && R.second==-1) return root;
    else root->right=constree(0 , s.substr(R.first+1 , R.second-R.first-1));
    
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
	string s="1(2(4(8))(5(9)))(3(6(7))(7(8)(9)))";
	Node* root=constree(0, s);
    
	preOrder(root);
	return 0;
}