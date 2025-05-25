class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [p, u] = pq.top(); pq.pop();
            if (u == end_node) return p;
            for (auto &[v, edgeProb] : adj[u]) {
                if (prob[v] < p * edgeProb) {
                    prob[v] = p * edgeProb;
                    pq.push({prob[v], v});
                }
            }
        }

        return 0.0;
    }
};