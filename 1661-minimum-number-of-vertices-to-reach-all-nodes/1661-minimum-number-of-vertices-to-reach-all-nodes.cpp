class Solution {
    int cnt = 0;
    vector<vector<int>> adj;
    vector<bool> vist;

    // void DFS(int source) {
    //     if (vist[source]) return;
    //     cnt++;
    //     vist[source] = true;
    //     for (auto& neigh : adj[source]) {
    //         if (vist[neigh]) continue;
    //         DFS(neigh);
    //     }
    // }

public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        adj.resize(n); 
        vist.resize(n, false);

        vector<int>degree(n,0);
        
        for (auto& values : edges) {
            adj[values[0]].push_back(values[1]);
            degree[values[1]]++;
        }

        // vector<int> ans;

        // for (int i = 0; i < n; i++) {
        //     if (!vist[i]) {
        //         DFS(i);
        //         ans.push_back(i);
        //     }
        // }
        
        // return ans;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(degree[i]==0)ans.push_back(i);
        }
        return ans;
    }
};
