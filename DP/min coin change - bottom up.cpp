class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int *dp = new int[amount + 1];
        
        for(int i = 0; i <= amount; i++) {
            dp[i] = INT_MAX;
        }
        
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++) {
           for(int j = 0; j < coins.size(); j++) {
               if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                      dp[i] = min(dp[i], dp[i - coins[j]] + 1);
               }
         }

        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};