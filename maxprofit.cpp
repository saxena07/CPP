#include<iostream>
#include<vector>
using namespace std;

 int maxProfit(vector<int>& prices) 
    {
        int max_profit = 0, opt_price;
        int min_price = INT_MAX;
        int n = prices.size();
        
        for (int i = 0; i < n; i++) {
            int opt_price = prices[i];
            if (opt_price < min_price) {
                min_price = opt_price;
            }
            else if (opt_price - min_price > max_profit) {
                max_profit = opt_price - min_price;
            }
            else {
                continue;
                
            }
        }
        
        return max_profit;
    }

int main(){
   vector<int> N={30,20,10};
   cout<<maxProfit(N);
    return 0;
}