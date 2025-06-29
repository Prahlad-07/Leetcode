class Solution {
private:
    vector<int> findOrder(vector<vector<int>>& prerequisites, int k) {
        vector<int> order;
        vector<vector<int>> adj(k);
        vector<int> indegree(k, 0);
        
        for (auto& val : prerequisites) {
            // b must be done before a ⇒ b → a
            adj[val[1]].push_back(val[0]);
            indegree[val[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            order.push_back(top);
            for (auto& neigh : adj[top]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }

        return order;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order = findOrder(prerequisites, numCourses);
        return order.size() == numCourses;
    }
};
