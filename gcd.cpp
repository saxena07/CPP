	#include <iostream>
	#include <bits/stdc++.h>
	using namespace std;

	// bool fun(string &s, string s2, bool c, int i, int prev, int n, vector<int> &dp){
	// 	// if(s2.size()>n) return false;
	// 	for(int j=prev;j<i;j++) {
	// 	if(s2[j]==s[j]) continue; 
	// 	else return false;}
	// 	if(i==n) return true;
	// 	if(dp[i]!=-1) return dp[i];
	// 	if(c){
	// 	if(s2!=""){
	// 		bool a=fun(s, s2+s[i], false, i+1, i, n, dp), b;
	// 		if(i+s2.size()>n) b=false;
	// 		else b=fun(s, s2+s2, true, i+s2.size(), i, n, dp);
	// 		return  dp[i]=a||b;
	// 		}
	// 	else return dp[i]=fun(s, s2+s[i], false, i+1, i, n, dp);
	// 	}
	// 	if(i+s2.size()>n) return false;
	// 	return dp[i]=fun(s, s2+s2, true, i+s2.size(), i, n, dp);
	// }

void fun(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 0 || n==1){cout << "YES" << endl; return;}
    string s1 = "";
    int c = 1;
    while (s1.size() < s.size())
    {
        if (c) s1 += s[(int)s1.size()];
        else  s1 += s1;
        c ^= 1;
    }
    if (s1 == s) cout << "YES" << endl;
    else cout << "NO" << endl;
}

	int main() {
		// your code goes here
		int count;
		cin>>count;
		while(count-->0){
		// int n;
		// cin>>n;
		// string s;
		// cin>>s;
		fun();
	}
		return 0;
	}
