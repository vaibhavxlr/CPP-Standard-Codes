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
    lli T, sum_x = 0, sum_y = 0, sum_z = 0;
    cin >> T;
    while(T--){
        lli x, y, z;
        cin >> x >> y >> z;
        sum_x += x;
        sum_z += z;
        sum_y += y;
        
        
    }
    if((sum_y == 0) && (sum_z == 0) && (sum_x == 0)) 
        cout << "YES" << endl;
    else 
        cout << "NO" <<endl;
    
    
}
    