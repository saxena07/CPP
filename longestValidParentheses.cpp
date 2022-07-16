 #include<iostream>
 #include<stack>
 #include<vector>
 using namespace std;

    int longestValidParentheses(string s) {
        stack<char> a;
        int j=0;
        vector<int> c={0};
        if(s.empty()){
            return 0;
        }
        else{
        for (int i = 0; i < s.size(); i++)
        {
         if(s[i]=='(')
          {
             a.push(s[i]);
             }
         
          else {
              if(!a.empty()){
                  if(a.top()=='('){
                      c[j]=c[j]+2;
                      a.pop();
                  }else{
                      a.push(s[i]);
                  }
              }else{
                  a.push(s[i]);
                  j=j+1;
              }
                       
            }
        }}
        int max=c[0];
        for (int i = 0; i <= j; i++)
        {
            if(max<c[i])
            max=c[i];
        }
        
        return max;
    }

int main(){
    string a;
    cin>>a;
    int s = longestValidParentheses(a);
    cout<<s;
    return 0;
}
