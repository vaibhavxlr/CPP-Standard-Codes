#include <bits/stdc++.h>
#include <iostream>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int curmax, curmin, prevmax, prevmin, ans;
        curmax = curmin = prevmax = prevmin = ans = nums[0];
        
        for(int  i = 1; i < nums.size(); i++){
            
            curmax = max(prevmax * nums[i], max(prevmin * nums[i] , nums[i]));
            curmin = min(prevmax * nums[i], min(prevmin * nums[i], nums[i]));
    
            ans = max(ans, curmax);
            prevmax = curmax;
            prevmin = curmin;
        }
        

        return ans;
        
        
    }
};