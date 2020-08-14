class Solution {
public:
    void sortColors(vector<int>& nums) {
            
            int low, mid, high;
            low = mid = 0;
            high = nums.size() - 1;
        
            for(int i = 0; i < nums.size(); i++) {
                if(mid < high)
                    if(nums[mid] == 0) {
                        swap(nums[mid++], nums[low++]);
                    }

                    else if(nums[mid] == 1){
                        mid++;
                    }

                    else{
                        swap(nums[mid], nums[high--]); //don't shrink the range in this case that is mid++ because swapped element which came from high position could be 0 or 1, that is not necessary to shrink the mid but while swapping with low position it is guaranteed that mid has to shrunken becaue low is increasing
                }
                
            }
   
    }
};