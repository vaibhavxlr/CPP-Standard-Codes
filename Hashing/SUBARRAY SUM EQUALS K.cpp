class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        if(nums.size() == 0) {
            return 0;
        }
        
        
        int N = nums.size();
        
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        
        for(int i = 0; i < N; i++) {
            
           sum += nums[i];  
            
           if(sum == k) {
                count++;
            }
             
           if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
                mp[sum]++;
            } 
            
           else {
                mp[sum]++;
            }
            
        }
        
        return count;
        
    }
};