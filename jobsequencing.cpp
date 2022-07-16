// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    int getmax(vector<int> &vw, int n, vector<bool> &visited){
        int max=-1, in;
        for(int i=0;i<n;i++) if(visited[i]==0 && max<vw[i]) {max=vw[i]; in=i;}
        visited[in]=1;
        return in;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<int> vw(n);
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++) vw[i]=arr[i].value/arr[i].weight;
        double ans=0;
        while(W!=0){
            int c=getmax(vw, n, visited);
            if(arr[c].weight<=W) {
              W-=arr[c].weight;
            //   cout<<arr[c].value<<" ";
              ans+=arr[c].value;  
            }
            else{
                // cout<<vw[c]<<" "<<W<<endl;
                ans+=(vw[c]*W);
                W=0;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n=3, W=50;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends