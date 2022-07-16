#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    using std::cout;
    using std::cin;
    
    char s[100];
    gets(s);
    int u=0,l=0;

    for(int i=0;i<strlen(s);i++){
      if(int(s[i])>=65 && int(s[i])<=90)
      u++;
      else if (int(s[i])>=97 && int(s[i])<=122)
      l++;}
      if(u>l){for(int i=0;i<strlen(s);i++){
      cout<<(char)toupper(s[i]);
      }
      }
      else{for(int i=0;i<strlen(s);i++){
      cout<<(char)tolower(s[i]);
      }}

    return 0;
}