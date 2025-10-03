class Solution {
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
private:
private:
    int DFS(vector<vector<int>>& grid, int i, int j, int val, int& cnt, vector<vector<bool>>& vist) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] >= val || vist[i][j]) 
            return 0;

        vist[i][j] = true;
        cnt++;

        DFS(grid, i + 1, j, val, cnt, vist);
        DFS(grid, i - 1, j, val, cnt, vist);
        DFS(grid, i, j + 1, val, cnt, vist);
        DFS(grid, i, j - 1, val, cnt, vist);

        return cnt;
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // vector<int> ans;
        // for(auto &val : queries) {
        //     vector<vector<bool>> vist(grid.size(), vector<bool>(grid[0].size(), false));
        //     int cnt = 0;
        //     int points = DFS(grid, 0, 0, val, cnt, vist);  
        //     ans.push_back(points);
        // }
        // return ans;

       vector<int> ans(queries.size(), 0);  
        vector<pair<int, int>> arr;
        for(int i = 0; i < queries.size(); i++)
            arr.push_back({queries[i], i});
        sort(arr.begin(), arr.end());

        int cnt = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        for(auto& [val, idx] : arr) {
            while(!pq.empty() && pq.top().first < val) {
                auto [value, position] = pq.top();
                pq.pop();
                cnt++;
                int i = position.first;
                int j = position.second;

                for(auto& [dx, dy] : dir) {
                    int ni = i + dx;
                    int nj = j + dy;
                    if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !visited[ni][nj]) {
                        visited[ni][nj] = true;
                        pq.push({grid[ni][nj], {ni, nj}});
                    }
                }
            }
            ans[idx] = cnt;
        }
        return ans;
    }
};