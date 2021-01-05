#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)

bool check(string st) {
        int count = 0;
        char last = st[0];
        
        for(int j = 1; j < st.size(); j++) {
            if(st[j] != last) {
                last = st[j];
                count++;
            }            
        }
        
        if((count == 0 && st[0] == '0') || count > 2 || (count == 2 && st[0] == '1')) 
            return false;
        
        else
            return true;
}


main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli T;
    cin >> T;
    vector<string> st;
    
    while(T--){
        string s;
        cin >> s;
        if(check(s)) cout << "YES\n";
	    else cout << "NO\n";
    }
    
}
    