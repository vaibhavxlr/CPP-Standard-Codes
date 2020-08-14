class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last1, last2, finale;
        last1 = m - 1;
        last2 = n - 1;
        finale = nums1.size() - 1;
        
        if(last1 < 0) {
            nums1 = nums2;
        }
        
        if(last2 < 0) {
            return;
        }
        
        while(finale >= 0) {
            if(last1 >= 0 && last2 >= 0 && (nums1[last1] >= nums2[last2])) {
                nums1[finale] = nums1[last1];
                finale--;
                last1--;
            }
            else if(last2 >= 0) {
                nums1[finale] = nums2[last2];
                finale--;
                last2--;
            }
            else
                finale--;
        }
    
        
    }
};