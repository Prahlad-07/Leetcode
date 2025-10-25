class Solution {
    /*
    private:
    int shortestPath(vector<vector<pair<int,int>>>& adj, int n) {
        vector<int> dist(n, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v, w] : adj[u]) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1];
    }

    void dfs(int node, int n, vector<vector<pair<int,int>>>& adj, int cost, int minCost, int &cnt) {
        if(cost > minCost) return;
        if(node == n-1) {
            if(cost == minCost) cnt++;
            return;
        }

        for(auto &[v, w] : adj[node]) {
            dfs(v, n, adj, cost + w, minCost, cnt);
        }
    }

    */
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
                    cout<<ways[v]<<"+"<<ways[u]<<endl;
                    ways[v] = (ways[v] + ways[u]) % MOD;
                    
                }
            }
        }
        for(int i = 0; i < ways.size(); i++){
            // cout<<"ways from node"<<i <<" is: "<<ways[i]<<endl;
        }
        return ways[n-1] % MOD;
    }
};
