#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0) {
            return 0;
        }
        
        int ans = INT_MIN;
        unordered_set<char> st;
        deque<char> dq;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(st.find(s[i]) != st.end()) {
                int leng = dq.size();
                ans = max(ans, leng);
                
                while(dq.front() != s[i]) {
                    st.erase(dq.front());
                    dq.pop_front();
                } 
                
                st.erase(dq.front());
                dq.pop_front();
            }
            
            dq.push_back(s[i]);
            st.insert(s[i]);
        }
        
        int len = st.size();
        
        return ans == INT_MIN ? s.size() : max(len, ans);
    }
};