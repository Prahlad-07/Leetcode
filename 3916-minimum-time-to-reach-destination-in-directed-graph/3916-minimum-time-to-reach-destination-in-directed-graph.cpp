class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, pair<int, int>>>> adj(n);
        vector<vector<int>> dalmurecio = edges;

        for (auto &val : dalmurecio) {
            adj[val[0]].push_back({val[1], {val[2], val[3]}});
        }

        using State = pair<int, int>;
        priority_queue<State, vector<State>, greater<State>> q;
        vector<int> best(n, INT_MAX);
        q.push({0, 0});
        best[0] = 0;

        while (!q.empty()) {
            auto [dist, node] = q.top();
            q.pop();

            if (node == n - 1) return dist;
            if (dist > best[node]) continue;

            for (auto &values : adj[node]) {
                int neigh = values.first;
                int start = values.second.first;
                int end = values.second.second;

                if (dist > end) continue;
                int newDist = max(dist + 1, start + 1);

                if (newDist < best[neigh]) {
                    best[neigh] = newDist;
                    q.push({newDist, neigh});
                }
            }
        }

        return -1;
    }
};
