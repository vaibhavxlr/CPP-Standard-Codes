class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size() < 4) {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        
        vector< vector<int> > ans;
        
        for(int i = 0; i < nums.size(); i++) {
        
            int target_3 = target - nums[i];
            
            for(int j = i + 1; j < nums.size(); j++) {
            
                int target_2 = target_3 - nums[j];
                
                int front = j + 1;
                
                int back = nums.size() - 1;
                
                while(front < back) {
                
                    if(nums[front] + nums[back] < target_2) {
                        front++;
                    }
                  
                    else if(nums[front] + nums[back] > target_2) {
                        back--;
                    }
                  
                    else {
                        vector<int> quadruplet(4, 0);
                        
                        quadruplet[0] = nums[i]; 
                        
                        quadruplet[1] = nums[j];
                        
                        quadruplet[2] = nums[front];
                        
                        quadruplet[3] = nums[back];
                        
                        ans.push_back(quadruplet);
                        
                        while(front < back && nums[front] == quadruplet[2])                           {
                            front++;        
                        }
                        
                        while(front < back && nums[back] == quadruplet[3]) {
                            back--;
                        }
                        
                    }
                    
                }
                
                while(j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }
            
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        
        return ans;
    }
};