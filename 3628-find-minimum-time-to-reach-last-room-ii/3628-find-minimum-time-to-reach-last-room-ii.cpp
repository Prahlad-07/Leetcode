class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> vist(n, vector<bool>(m, false));

        priority_queue<pair<pair<int, int>, pair<int, int>>,
                       vector<pair<pair<int, int>, pair<int, int>>>,
                       greater<pair<pair<int, int>, pair<int, int>>>> pq;

        dist[0][0] = 0;
        pq.push({{0, 0}, {0, 0}});
        vist[0][0] = true;

        while (!pq.empty()) {
            auto [x, pos] = pq.top(); pq.pop();
            int i = pos.first, j = pos.second;
            int time = x.first, turn = x.second;

            if (i == n - 1 && j == m - 1) return dist[n-1][m-1];

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vist[ni][nj]) {
                    int newTime = max(grid[ni][nj], time);
                 
                    if (turn == 1) {
                        newTime += 2;
                    } else {
                        newTime += 1;
                    }

                    int newTurn = (turn == 1) ? 0 : 1;

                    if (newTime < dist[ni][nj]) {
                        dist[ni][nj] = newTime;
                        pq.push({{newTime, newTurn}, {ni, nj}});
                    }
                    vist[ni][nj] = true;
                }
            }
        }

        return dist[n-1][m-1];
    }
};