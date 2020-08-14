class Solution {
public:
    int findDuplicate(vector<int>& nums) { 
      if(nums.size() > 1) {
          
          int slow = nums[0]; //can't put zero because then first while loop won't work, so we move both slow and fast one step each.
          int fast = nums[nums[0]];
          
          while(slow != fast) {
              slow = nums[slow];
              fast = nums[nums[fast]];
          }
          
          fast = 0;
          
          while(slow != fast) {
              slow = nums[slow];
              fast = nums[fast];
          }
          
          return slow;
          
      }
        
      return -1;
    }
    
};