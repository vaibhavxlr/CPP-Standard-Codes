class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i, j;
        
        for( i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                break;
            }
        }
        
        if(i == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        for(j = i + 1; j < nums.size(); j++) {
            if(nums[j] <= nums[i]) {
                break;
            }
        }
        
        swap(nums[i], nums[j - 1]);
        sort(nums.begin() + i + 1, nums.end());
        
    }

};