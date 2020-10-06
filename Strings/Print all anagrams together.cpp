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
    map<string, vector<int> > mp;
    
    vector<string> v;
    v = {"cat", "dog", "tac", "god", "act"};
    
    for(int i = 0; i < v.size(); i++) {
        string temp = v[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(i);
    }
    
    vector<string> finall;
    
    for(auto it = mp.begin(); it != mp.end(); it++) {
        vector<int> ans = it -> second;
        for(int i : ans) {
            finall.push_back(v[i]);
        }
    }
    
    for(auto str : finall) {
        cout << str << " ";
    }
 
 
}   