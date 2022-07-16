#include <cstring>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
#define M 3
#define N 3
int c=0;

// Let the given dictionary be following
string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GO" };
int n = sizeof(dictionary) / sizeof(dictionary[0]);

// vector<int> x={1,1,1,0,0,-1,-1,-1};
// vector<int> y={-1,0,1,-1,1,1,0,-1};
 
bool isword(string s){
    for(int i=0;i<4;i++){
        if(s.compare(dictionary[i])==0) return true;
    }
    return false;
}



void fwutil(char boggle[M][N], string s, int i, int j, vector<vector<bool>> &v){
v[i][j]=true;
s+=boggle[i][j];
if(isword(s)) cout<<++c<<". "<<s<<" "<<endl;
// for(int a=0;a<8;a++){
//     if(i+x[a]>=0 && i+x[a]<M && j+y[a]>=0 && j+y[a]<N && !v[i+x[a]][j+y[a]]){
//         fwutil(boggle, s, i+x[a], j+y[a], v);
//     }
// }
  for (int row = i - 1; row <= i + 1 && row < M; row++)
        for (int col = j - 1; col <= j + 1 && col < N; col++)
            if (row >= 0 && col >= 0 && !v[row][col])
                fwutil(boggle, s, row, col, v);
s.erase(s.length() - 1);
v[i][j] = false;
}

void findWords(char boggle[M][N]){
vector<vector<bool>> v(M, vector<bool> (N, false));
string s="";

for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
        fwutil(boggle, s, i, j, v);

}



int main()
{
    char boggle[M][N] = { { 'G', 'I', 'Z' },
                          { 'U', 'E', 'K' },
                          { 'Q', 'S', 'E' } };
 
    cout << "Following words of dictionary are present : \n\n";
    findWords(boggle);
    return 0;
}