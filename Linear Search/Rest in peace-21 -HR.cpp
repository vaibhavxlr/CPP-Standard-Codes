#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define endl "\n"
#define fLoop for(lli i = 0; i < N; i++)

bool check(lli N) {
    if(N % 21 == 0)
        return true;
    else {
        int last = -11;
        while(N > 0) {
            if(last == -11)
                last = N % 10;
            else if(last == 1 and N % 10 == 2) 
                return true;
            else 
                last = N % 10;
            N /= 10;
        }
    }
    return false;
}

main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli T;
    cin >> T;
    
    while(T--){
        lli N;
        cin >> N;
        if(check(N)) {
            cout << "The streak is broken!" << endl;
        }
        else 
            cout << "The streak lives still in our heart!" << endl;
    }
  
    
}
    