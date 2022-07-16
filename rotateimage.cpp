#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
  int s=1,k=0,l=0,c=0;
  while(s<matrix[0].size()-1){
  int n = matrix[0].size()-s+1;
  for (int i = 0; i < n-s; i++)
  {    c++;
       int temp = matrix[k][l+i];
       matrix[k][l+i]=matrix[n-1-i][l];
       matrix[n-1-i][l]=matrix[n-1][n-1-i];
       matrix[n-1][n-1-i]=matrix[k+i][n-1];
       matrix[k+i][n-1]=temp;
  }
  k++;
  l++;
  s++;
  }
  cout<<c<<endl;
  
  int z = matrix.size();

  for (int i = 0; i < z; i++)
  { for (int j = 0; j < z; j++)
  {
      cout<<matrix[i][j]<<" ";
  }
  cout<<endl;
  }
  

}


int main(){
    vector<vector <int>> v={{1,2},{3,4}};
    rotate(v);

    return 0;
}