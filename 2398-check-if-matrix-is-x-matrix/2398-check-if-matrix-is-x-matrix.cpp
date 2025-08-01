class Solution {
private:
    bool isValid(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == j || i + j == n - 1){
                    if(grid[i][j] == 0) return false;  
                }
                else{
                    if(grid[i][j] != 0) return false;
                }
            }
        }
        return true;
    }

public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        return isValid(grid);
    }
};
