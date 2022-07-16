#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> transpose(int a[][3], int n)
{
 vector<vector<int>> b;   
    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < n; j++)
      { 
           
                b[i][j]=a[j][i];
           

        }
    }
    
   

    for (int i = 0; i < n; i++)
    {for (int j = 0; j < n; j++){
        cout<<b[i][j]<<" ";
    }
        cout<<endl;
    }
    
    return b;
}


int main(){
int a[][3]={{1,2,3}, {4,5,6}, {7,8,9}} ,n=3;
 for (int i = 0; i < n; i++)
    {for (int j = 0; j < n; j++){
        cout<<a[i][j]<<" ";
    }
        cout<<endl;
    }
transpose(a,n);
    return 0;
}