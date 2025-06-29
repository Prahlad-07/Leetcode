class Solution {
private:
    vector<int> findOrder(vector<vector<int>>& conditions, int k) {
        vector<int> order;
        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1, 0);
        
        for (auto& val : conditions) {
            adj[val[0]].push_back(val[1]);
            indegree[val[1]]++;
        }
        
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            auto top = q.front();
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
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        /*

        ** Radhe Radhe **
        ------------------



        Prahlad remember this pattern, here the problem is all about the ordering, and we know for ordering the only thing that come in our mind is topological sorting;
        

        now let's see what we will do in this -->

        find the order for all row and columns saprately using kahn's algo;
        then check for each k ,if all elemements in range of 1-k is not avilabel then we can't form our answer, so return empty list;
        other find the pos of each element in row and col and build the answer matrix on the basis of that---
        */
        
        vector<vector<int>> ans(k, vector<int>(k, 0));

        vector<int> rowOrder = findOrder(rowConditions, k);
        vector<int> colOrder = findOrder(colConditions, k);

        if (rowOrder.size() != k || colOrder.size() != k) return {};
        
        for (int val = 1; val <= k; val++) {
            int row = -1;
            int col = -1;
            for (int i = 0; i < rowOrder.size(); i++) {
                if (rowOrder[i] == val) {
                    row = i;
                    break;
                }
            }
            for (int i = 0; i < colOrder.size(); i++) {
                if (colOrder[i] == val) {
                    col = i;
                    break;
                }
            }

            ans[row][col] = val;
        }
        return ans;
    }
};
