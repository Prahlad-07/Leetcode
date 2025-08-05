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
        vector<vector<int>> max_i(m, vector<int>(n, -1)),
            max_j(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        int steps = 0;

        while (!q.empty()) {
            ++steps;
            int q_size = q.size();

            for (int q_index = 0; q_index < q_size; ++q_index) {
                auto [i, j] = q.front();
                q.pop();

                if (i == m - 1 && j == n - 1) {
                    return steps;
                }

                for (int k = i + 1; k < m && k - i <= g[i][j]; ++k) {
                    if (max_i[k][j] == -1) {
                        q.push({k, j});
                        max_i[k][j] = i + g[i][j];
                    } else {
                        k = max_i[k][j];
                    }
                }

                for (int k = j + 1; k < n && k - j <= g[i][j]; ++k) {
                    if (max_j[i][k] == -1) {
                        q.push({i, k});
                        max_j[i][k] = j + g[i][j];
                    } else {
                        k = max_j[i][k];
                    }
                }
            }
        }

        return -1;
    }
};
