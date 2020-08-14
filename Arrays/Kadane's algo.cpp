#include <bits/stdc++.h>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, total = INT_MIN;
        for(int i : nums)
        {
          sum += i;
          total = max(total, sum);
          sum = max(sum, 0);
        }    
        return total;
    }
};