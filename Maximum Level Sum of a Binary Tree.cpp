#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<int> v={0};
int s=0;

  int maxLevelSum(TreeNode* root) {
        
    }

void calc(TreeNode* root, int stage){
    if(root==NULL){
        return;
    }
    else{
       v[stage]=v[stage]+root->val;
       v[stage+1]=0;
    }
    s=stage+1;
    if(root ->left!=NULL){
      calc(root->left,s);
    }

    if(root ->right!=NULL){
        calc(root->right,s);
    }

  return;
}


int main(){
    

for (int i = 0; i < 10; i++)
{
    v[i]=v[i]+i;
    cout<<v[i]<<" , ";
}
cout<<endl<<v[2];



return 0;
}
