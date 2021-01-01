#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli T;
    //cin >> T;
    //while(T--){
        lli A[5][5], x, y;
        for(lli i = 0 ; i < 5 ; i++){
            for(lli j = 0 ; j < 5 ; j++){
                cin >> A[i][j];
                if(A[i][j] == 1){
                   x = i, y = j; 
                }
            }
        }
        lli sum = abs(2-x) + abs(2-y);
       cout << sum << endl; 
    //}
    
}
    