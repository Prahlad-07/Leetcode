// class Solution {
//     vector<vector<int>> dp;

//     int solve(vector<vector<int>>& grid, int i, int j, int n, int m) {
//         if (i == n - 1 && j == m - 1) return 0;
//         if (i >= n || j >= m) return 1e9 / 2;
//         if (dp[i][j] != -1) return dp[i][j];
//         int ans = 1e9;
//         for (int inc = 1; inc <= grid[i][j]; inc++) {
//             ans = min(ans, 1 + solve(grid, i + inc, j, n, m));
//             ans = min(ans, 1 + solve(grid, i, j + inc, n, m));
//         }
//         return dp[i][j] = ans;
//     }

// public:
//     int minimumVisitedCells(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         dp.resize(n, vector<int>(m, -1));
//         int ans = solve(grid, 0, 0, n, m);
//         return ans >= 1e9 / 2 ? -1 : ans + 1;
//     }
// };



class Solution {
public: 
    int minimumVisitedCells(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> mi(m, vector<int>(n, -1)), mj(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        int s = 0;

        while (!q.empty()) {
            ++s;
            int z = q.size();
            while (z--) {
                auto [x, y] = q.front();
                q.pop();
                if (x == m - 1 && y == n - 1) return s;

                for (int k = x + 1; k < m && k - x <= g[x][y]; ++k) {
                    if (mi[k][y] == -1) {
                        q.push({k, y});
                        mi[k][y] = x + g[x][y];
                    } else {
                        k = mi[k][y];
                    }
                }

                for (int k = y + 1; k < n && k - y <= g[x][y]; ++k) {
                    if (mj[x][k] == -1) {
                        q.push({x, k});
                        mj[x][k] = y + g[x][y];
                    } else {
                        k = mj[x][k];
                    }
                }
            }
        }
        return -1;
    }
};

