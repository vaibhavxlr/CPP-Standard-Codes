class Solution {
public:
    int helper(vector<int> nums) {
        
        if(nums.size() == 0) {
            return  0;
        }
        int *dp = new int[nums.size()];
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = 1; // dp[i] shows length longest increasing subsequence until index 'i' from 0
        }
        
        for(int i = 1; i < nums.size(); i++) {
            int temp = i - 1;
            while(temp >= 0) {
                if(nums[temp] < nums[i]) {
                    dp[i] = max(dp[i], dp[temp] + 1);
                }
                temp--;
            }
        }
        
       int maxim = 1;
       for(int i = 0; i < nums.size(); i++) {
           if(dp[i] > maxim) {
               maxim = dp[i];
           }
       }
        
       return maxim;// we need to return maximum increasing subsequence not maximum increasing subsequence ending at nums.size() - 1, that's why we are not returning dp[nums.size() - 1]
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        return helper(nums);
    
    }
};


///binary search dp method


#include <bits/stdc++.h>
class Solution {
public:
    int helper(vector<int> nums) {
        vector<int> hold;
        // hold the LIS
        for(int i = 0; i < nums.size(); i++) {
            auto itr  = lower_bound(hold.begin(), hold.end(), nums[i]);
            if(itr == hold.end()) {
                hold.push_back(nums[i]);
            }
            else {
                *itr = nums[i];
            }
        }
        
        return hold.size();
    }
        
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums);
    }
};
