#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)

int fib(int T) {
    if(T == 0 or T == 1)
        return T;
    return fib(T - 1) + fib(T - 2);
}

int fib_td(int T, int *dp) {
    if(T == 0 or T == 1)
        return dp[T] = T;
        
    if(dp[T] != -1)
        return dp[T];
    
    return dp[T] = fib_td(T - 1, dp) + fib_td(T - 2, dp);
}

int fib_bu(int T, int *dp) {
    dp[0] = 0; dp[1] = 1;
    
    for(int i = 2; i <= T; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
        
    return dp[T];
}


main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli T;
    cin >> T;
    cout << fib(T) << endl;
    
    int *dp = new int[T + 1];
    
    for(int i = 0; i <= T; i++) {
        dp[i] = -1;
    }
    
    cout << fib_td(T, dp) << endl; //top down
    cout << fib_bu(T, dp) << endl; //bottom up
    
}
    