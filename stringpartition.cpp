#include <iostream>
#include<string> 
#include<vector> 
using namespace std;

bool ispalindrome(string str){
int low=0;
int high=str.size()-1;
while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void partition(string a , vector<vector<string>>& ans, vector<string> &anstillnow, int start, int end){
if(start>=end){ 
    ans.push_back(anstillnow);
    return;}

for(int i=start;i<end;i++){
if(ispalindrome(a.substr(start,i-start+1))){
anstillnow.push_back(a.substr(start,i-start+1));
partition(a,ans,anstillnow, i+1, end);
anstillnow.pop_back();
}
}
}



int main(){
    string a = "tenet";
    vector<vector<string>> ans;
    vector<string> anstillnow;
    partition(a,ans,anstillnow, 0, 5);

    for (int i = 0; i < ans.size(); i++)
    {for (int j = 0; j < ans[i].size(); j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
    }
    
    return 0;
}