#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)

lli findWays(lli N, lli M, lli dp[]) {
    //base cas
    
    if(N < 0)
        return 0;
    if(N == 0) {
        return 1;
    }
    
    if(dp[N] != 0)
        return dp[N];

    lli x = findWays(N - 1, M, dp) % mod;
    x += findWays(N - M, M, dp) % mod;
    return  dp[N] = x % mod;
    
}




int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli T;

    cin >> T;
    
	lli dp[100001];
    
    while(T--){
        lli N, M;
        cin >> N >> M;
        for(int i = 0; i < 100001; i++) dp[i] = 0;
        cout << findWays(N, M, dp) % mod << endl;
    }
  
    return 0;
}
    