class Solution {
public:
    int trap(vector<int>& height) {
        
        
        int N =  height.size() - 1;
        if(N < 0) {
            return 0;
        }
        vector<int> maxl(N + 1);
        vector<int> maxr(N + 1);
        
        maxl[0] = height[0];
        
        for(int i = 1; i <= N; i++) {
            maxl[i] = max(maxl[i - 1], height[i]);
        }
        
        maxr[N] = height[N];
        
        for(int i = N - 1; i >= 0; i--) {
            maxr[i] = max(maxr[i + 1], height[i]);
        }
        
        int water = 0;
        
        for(int i = 0; i <= N; i++) {
            maxl[i] = min(maxr[i], maxl[i]);
            water += (maxl[i] - height[i]);
        }
        
        
        return water;
    }
};