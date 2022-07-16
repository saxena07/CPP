#include<iostream>
using namespace std;

string reverseOnlyLetters(string s) {
        string a;
        int i=0,j=s.size()-1;
        while(i!=j){
            
            cout<<s[i]<<" "<<s[j]<<endl;
            if(s[i]=='-'){
            i++;}
            else if(s[j]=='-'){
            j--;}
            else{
            swap(s[i],s[j]);
            i++;
            j--;
            }
        }
        return s;

        
    }

int main(){
    string s;
    cin>>s;

    string a = reverseOnlyLetters(s);
    cout<<a;
    return 0;
}