class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool BFS(vector<vector<int>>& grid, int mid, int n) {
        vector<vector<bool>> vist(n, vector<bool>(n, false));
        if (grid[0][0] > mid) return false;

        queue<pair<int, int>> q;
        q.push({0, 0});
        vist[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front(); 
            q.pop();

            if (i == n - 1 && j == n - 1) return true;

            for (int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                    !vist[ni][nj] && grid[ni][nj] <= mid) {
                    vist[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 1e9, right = -1;

        for (auto& arr : grid) {
            for (auto& val : arr) {
                right = max(right, val);
                left = min(left, val);
            }
        }

        int minTime = 1e9;
        while (right >= left) { 
            int mid = (left + right) / 2;
            if (BFS(grid, mid, n)) {
                minTime = min(minTime, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return minTime;
    }
};
