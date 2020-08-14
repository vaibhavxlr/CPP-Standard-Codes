class Solution {
public:
   static bool sortbycol(const vector<int> &A, const vector<int> &B) {
        return A[0] < B[0];    
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return {};
        }
        
        vector<vector<int> > ans;
        
    
        sort(intervals.begin(), intervals.end(), sortbycol);
        
        int start = intervals[0][0]; //1
        int end = intervals[0][1]; //3
        
        for(int i = 1; i < intervals.size(); i++) {
            
            if(intervals[i][0] <= end) {
                end = max(end, intervals[i][1]); 
            }
            else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
        }
        ans.push_back({start, end});
        return ans;
    }
};