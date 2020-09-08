class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector< vector<int> > ans;
        
        if(nums.size() < 3) {
            return ans;
        }
        
        set<vector<int>> s;
        
        int low = 0;
        int high = nums.size() - 1;
        int mid = low + 1;
        
        sort(nums.begin(), nums.end());
        
        //vector< vector<int> > ans;
        
        while(low < nums.size()-2) { 
            
            if(mid < high) {
                
                if(nums[low] + nums[mid] + nums[high] == 0) {

                    vector<int> temp;
                    temp.push_back(nums[low]);
                    temp.push_back(nums[mid]);
                    temp.push_back(nums[high]);

                    s.insert(temp);
                    mid++;
                    high--;
                }

                else if(nums[low] + nums[mid] + nums[high] < 0) {
                    mid++;
                }
                
                else {
                    high--;
                }

                }
            
            else {
                low++;
                mid = low + 1;
                high = nums.size() - 1;
            }
       }
       
       for(auto a : s) {
           ans.push_back(a);
       } 
       
       return ans;
    }
};