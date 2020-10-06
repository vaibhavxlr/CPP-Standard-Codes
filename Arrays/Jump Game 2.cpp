class Solution {
public:
    
//     This problem has a nice BFS structure. Let's illustrate it using the example nums = [2, 3, 1, 1, 4] in the problem statement. We are initially at position 0. Then we can move at most nums[0] steps from it. So, after one move, we may reach nums[1] = 3 or nums[2] = 1. So these nodes are reachable in 1 move. From these nodes, we can further move to nums[3] = 1 and nums[4] = 4. Now you can see that the target nums[4] = 4 is reachable in 2 moves.

    int jump(vector<int>& nums) {
        
        if(nums.size() == 1) return 0;
        int maxReach = 0 + nums[0]; //stores maximum reach from any index initialised with 0 index
        
        int step = 1; // no of steps taken, assuming we took the first step be default
        
        int i = 0, k = 0;
        
        while(maxReach < nums.size() - 1) {
            step++;
            
            //traversing over the all reachable elements from the index i and try which one has maxReach
            
            for(int j = i + 1; j <= nums[i] + i; j++) {
                
                if(maxReach < (j + nums[j])) {
                    maxReach = nums[j] + j;
                    k = j;
                }    
                
                 //save that index as it can be our element on we jump from i
            }
            
            i = k;
            
         }
        
        return step;
    }
};