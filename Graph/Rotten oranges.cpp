class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rowCount = grid.size();
        int colCount = grid[0].size();        
        if(rowCount == 1 && colCount == 1 && grid[rowCount - 1][colCount - 1] == 0 )
            return 0;
        
        queue<pair<int, pair<int, int>>> q;
        
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(0,make_pair(i, j))); //1,0  
                }
            }
        }
        
        int time;
        
        while(!q.empty()) {
            time = q.front().first;
            int row = q.front().second.first; 
            int col = q.front().second.second; 
            q.pop();
            
            if(row + 1 < rowCount && grid[row + 1][col] == 1) {
                grid[row + 1][col] = 2;
                q.push({time + 1, {row + 1, col}});
            }
            
            if(row - 1 >= 0 && grid[row - 1][col] == 1) {
                grid[row - 1][col] = 2;
                q.push({time + 1, {row - 1, col}});
            }
            
            if(col + 1 < colCount && grid[row][col + 1] == 1) {
                grid[row][col + 1] = 2;
                q.push({time + 1, {row, col + 1}});
            }
            
            if(col - 1 >= 0 && grid[row][col - 1] == 1) {
                grid[row][col - 1] = 2;
                q.push({time + 1, {row, col - 1}});
            }
            
        }
        
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(grid[i][j] == 1)
                    return -1;
                
            }
        }
        
        return time;
    }
};