class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int count = 0, max_count = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
            }
            // 1, 1, 0 , 1 1 1
            if(nums[i] == 0) {
                max_count = max(count, max_count);
                count = 0;
            }
        }
        
        
        max_count = max(count, max_count);
        return max_count;
    }
};