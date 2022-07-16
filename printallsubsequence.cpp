
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
void printSubsequence(string a, string b){

if(a.empty()) {cout<<b<<endl; return;}
printSubsequence(a.substr(1), b+a[0]);
printSubsequence(a.substr(1), b);

}

int main()
{
    // output is set to null before passing in as a

    string output = "";
    string input = "abcd";
 
    printSubsequence(input, output);
 
 
    return 0;
}