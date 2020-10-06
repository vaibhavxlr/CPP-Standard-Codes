#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)

int minStepTD(int N, int dp[]) {
    if(N == 1) {
        return dp[1] = 0;
    }
    if(dp[N] != -1)
        return dp[N];
    
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    
    if(N % 2 == 0) 
        op2 = minStepTD(N / 2, dp);
    if(N % 3 == 0) 
        op3 = minStepTD(N / 3, dp);
    
    op1 = minStepTD(N - 1, dp);
    
    dp[N] = min(op1, min(op2, op3)) + 1;
    
    return dp[N];
}


int minStepBU(int N, int dp[]) {
 
    for(int i = 2; i <= N; i++) {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        
        if(i % 2 == 0)
          op2 = dp[i / 2];
        
        if(i % 3 == 0)
          op3 = dp[i / 3];
        
        op1 = dp[i - 1];
        
        dp[i] = min(op1, min(op2, op3)) + 1;
     
    }
    
    return dp[N];
}

main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli N;
    cin >> N;
    int *dp = new int[N + 1];    
    
    dp[0] = dp[1] = 0;
    
    cout << minStepBU(N, dp) << endl; //BOTTOM UP
    
    for(int i = 0; i <= N; i++) {
        dp[i] = -1;
    }
    
    cout << minStepTD(N, dp) << endl; // TOP DOWN
    
    
    
}
    