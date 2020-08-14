#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)

int helper(int *arr, int n) {
    
    int dp1[n], dp2[n];
    
    for(int i = 0; i < n; i++) {
        dp1[i] = arr[i];
        //dp2[i] = i;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp1[i] = max(dp1[i], dp1[j] + arr[i]);
                //dp2[i] = j;
            }
        }
    }
    
    int max = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        if(dp1[i] > max)
            max = dp1[i];
            
    }
    
    return max;
    
}

main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[] = {4, 6, 1, 3, 8, 4 ,6};
    
    cout << helper(arr, 7);
}
    