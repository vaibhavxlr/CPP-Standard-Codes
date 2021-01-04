#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop(i, a, b) for(lli i = a; i < b; i++)
main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    lli T;
    cin >> T;
    vector<string> v;
    
    while(T--) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    
    
    for(string s : v) {
        int i = 0;
        lli countS = 0, countSJ = 0;
        while(i < s.size()) {
            if(s[i] == 'S') {
                string big = s.substr(i, 7);
                string small = s.substr(i, 4);
                
                if(big == "SUVOJIT")
                    countSJ++, i += 7;
                
                else if(small == "SUVO")
                    countS++, i += 4;
                else i++;
            }
            else i++;
            
        }
        cout << "SUVO = " << countS << ", " <<  "SUVOJIT = " << countSJ << "\n";
    }
    
    
}
    