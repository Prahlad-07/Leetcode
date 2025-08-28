class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size(); 
        for(int i=1;i<n;i++){
            int row=0;
            int col=i;
            vector<int>temp;
            while(row<n && col<n){
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(),temp.end());
            row=0;
            col=i;
            int idx=0;
            while(row<n && col<n){
                grid[row][col]=temp[idx];
                idx++;
                row++;
                col++;
            }    
        }

        
                for(int i=0;i<n;i++){
                int row=i;
                int col=0;
                 vector<int>temp;
                 while(row<n && col<n){
                     temp.push_back(grid[row][col]);
                     row++;
                     col++;
                 }
             sort(temp.begin(),temp.end(),greater<int>());
              row=i;
            col=0;
            int idx=0;
            while(row<n && col<n){
              grid[row][col]=temp[idx];
                idx++;
                row++;
                col++;
            }    
                }

                return grid;
        
    }
};