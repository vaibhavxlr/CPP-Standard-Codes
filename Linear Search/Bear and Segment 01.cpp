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
    cin >> T;
    vector<string> st;
    
    while(T--){
        string s;
        cin >> s;
        st.push_back(s);
    }
    
    for(int i = 0; i < st.size(); i++) {
        int count = 0;
        char last = st[i][0];
        
        for(int j = 1; j < st[i].size(); j++) {
            if(st[i][j] != last) {
                last = st[i][j];
                count++;
            }            
        }
        
        if((count == 0 && st[i][0] == '0') || count > 2 || (count == 2 && st[i][0] == '1')) cout << "NO\n";
        
        else
            cout << "YES\n";
    }
  
    
}
    