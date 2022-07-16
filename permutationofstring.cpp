#include<iostream>
#include<vector>
using namespace std;

 void swap(int i, int j, string &S){
	        auto a=S[i];
	        S[i]=S[j];
	        S[j]=a;
	        return;
	    }
	   
	   
	    void find(int N, int i, string S, vector<string> & ans){
	        
	        if(i==N-1){
	         ans.push_back(S); 
	         cout<<S<<" ";
	        }
            else{
	        for(int k=i;  k<N; k++){
	        swap(k, i, S);
            // cout<<S<<" ";
	        find(N , i+1, S, ans);  
	        swap(k, i, S);
	        }
            }
	    }
	
		vector<string>find_permutation(string S)
		{
		   vector<string> ans;
		   find(S.size(), 0, S, ans);
		   return ans;
		}

int main(){
    string s="ABCD";
    find_permutation(s);

    return 0;
}        