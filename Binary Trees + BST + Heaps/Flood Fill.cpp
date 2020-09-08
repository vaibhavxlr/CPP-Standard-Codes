class Solution {
public:
    
    void helper(vector<vector<int>>& image, int sr, int sc,int color, int newColor) {
       //we need color to save old color of the pixel because we need to make sure we change color of those pixels which have the same old color
        //since 0, 1 or 2 isn't guaranteed to be colorless or old color or new color
        if(sr >= image.size() || sc >= image[0].size() || sr < 0 || sc < 0 ||  image[sr][sc] != color)         {
            return;
        }
        
        image[sr][sc] = newColor;
        
        helper(image, sr + 1, sc, color, newColor);
        helper(image, sr, sc + 1, color, newColor);
        helper(image, sr - 1, sc, color, newColor);
        helper(image, sr, sc - 1, color, newColor);

        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) { 
        if(image[sr][sc] == newColor)
            return image;
        helper(image, sr, sc, image[sr][sc], newColor);
        return image;
        
        
    }
};