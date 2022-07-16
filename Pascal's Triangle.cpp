#include<iostream>
#include<vector>
using namespace std;

  vector<vector<int>> generate(int numRows) {
       vector<vector <int>> a;
       if(numRows>=1) a.push_back({1});
       if(numRows>=2) a.push_back({1,1});
       for(int i=2;i<numRows; i++){
           vector<int> b;
           b.push_back(1);
           for(int j=1;j<i;j++) b.push_back(a[i-1][j-1]+a[i-1][j]); 
           b.push_back(1);
           a.push_back(b);
        }
       
         return a;
}


int main(){
    vector<vector<int>> b= generate(10);
    for (int i = 0; i < 10; i++)
    {for (int j = 0; j < i+1; j++)
    {
        cout<<b[i][j]<<" ";
    }
    cout<<endl;
    }
    
    
    return 0;
}