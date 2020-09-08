class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0) {
            return 0;
        }
        
        int minm = prices[0];
        int profit = INT_MIN;
        
        for(int i = 1; i < prices.size(); i++) {
            
            if(prices[i] > minm) {
                profit = max(profit, prices[i] - minm);
            }
            
            minm = min(minm, prices[i]);
        }
        
        if(profit == INT_MIN) {
            return 0;
        }
        return profit;
        
              
    }
};