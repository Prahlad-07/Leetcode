class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        // if (y <= x) return x - y;

        queue<pair<long long, int>> q;
        q.push({x, 0});
        unordered_set<long long> vis;
        vis.insert(x);

        while (!q.empty()) {
            auto [val, dist] = q.front();
            q.pop();

            if (val == y) return dist;

            if (val % 5 == 0 && vis.find(val / 5) == vis.end()) {
                q.push({val / 5, dist + 1});
                vis.insert(val / 5);
            }
            if (val % 11 == 0 && vis.find(val / 11) == vis.end()) {
                q.push({val / 11, dist + 1});
                vis.insert(val / 11);
            }
            if (vis.find(val + 1) == vis.end()) {
                q.push({val + 1, dist + 1});
                vis.insert(val + 1);
            }
            if (val > 0 && vis.find(val - 1) == vis.end()) {
                q.push({val - 1, dist + 1});
                vis.insert(val - 1);
            }
        }

        return 0;
    }
};
