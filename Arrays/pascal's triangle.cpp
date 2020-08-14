class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector< vector<int> > v;
        
        for(int i = 0; i < numRows; i++) {
            int j = 0;
            vector<int> temp;
            while(j <= i) {
                if(j == 0)
                    temp.push_back(1);
                
                else if(j == i)
                    temp.push_back(1);
                
                else
                    temp.push_back(v[i-1][j-1] + v[i-1][j]);
                
                j++;
            }
            v.push_back(temp);
        }
        
        return v;
    }
    
    
};