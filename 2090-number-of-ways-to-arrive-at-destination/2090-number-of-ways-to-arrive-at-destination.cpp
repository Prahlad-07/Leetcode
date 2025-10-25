class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(d > dist[u]) continue;

            for(auto &[v, w] : adj[u]) {
                if(d + w < dist[v]) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if(d + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
