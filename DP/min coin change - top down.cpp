#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)

int coinChange(int amount, int coins[], int noOfCoins, int dp[]) {
    //base case
    if(amount == 0)
        return 0;
    
    //look up
    if(dp[amount] != 0)
        return dp[amount];
    
    int minAmount = INT_MAX;
    
    for(int i = 0; i < noOfCoins; i++) {
        if(amount >= coins[i]) {
            dp[amount - coins[i]] = coinChange(amount - coins[i], coins, noOfCoins, dp);
            minAmount = min(minAmount, dp[amount - coins[i]] + 1);
        }
    }
    
    return dp[amount] = minAmount;
}

main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int amount = 15;
    int coins[] = {1, 7, 10};
    int dp[amount + 1] = {0};
    
    int noOfCoins = sizeof(coins) / sizeof(int);
    
    cout << coinChange(amount, coins, noOfCoins, dp);
}
    