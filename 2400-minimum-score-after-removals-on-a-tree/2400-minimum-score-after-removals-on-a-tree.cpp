const int N = 1e3+1;
vector<int> g[N];
vector<int> subtree_xor(N), val(N);
vector<int> st(N, 0), ed(N, 0);

vector<vector<bool>> is_ancestor(N, vector<bool>(N, false)); 

class Solution {
    inline int GetScore (int component1, int component2, int component3) {
        vector<int> all = {component1, component2, component3};
        sort (all.begin(), all.end());
        return (all[2] - all[0]);
    }
    
    void MarkAncestor (int src, int par, const int root) {
        is_ancestor [root][src] = true;
        
        for (auto i : g[src]) {
            if (i == par) continue;
            MarkAncestor (i, src, root);
        }
    }

    void dfs (int src, int par) {    
        subtree_xor[src] = val[src];  
        MarkAncestor (src, par, src);
        
        for (auto i : g[src]) {
            if (i == par) continue;
            
            dfs (i, src);
            subtree_xor[src] ^= subtree_xor[i];
        }
    }
    
    
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        for (int j = 0; j <= n; j ++) {
            g[j].clear();
            for (int i = 0; i <= n; i ++) is_ancestor[j][i] = false;
        }
        
        for (auto i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < n; i ++) val[i] = nums[i];
        
        dfs (0, 0);
        
        int ans = INT_MAX;
        
        for (int c1 = 1; c1 < n; c1 ++) {
            for (int c2 = c1+1; c2 < n; c2 ++) {
                if (c1 == c2) continue;
                                
                if (is_ancestor[c1][c2]) {
                    int comp1 = subtree_xor[c2];
                    int comp2 = subtree_xor[c2] ^ subtree_xor[c1];
                    int comp3 = subtree_xor[0] ^ comp1 ^ comp2;
                    
                    ans = min (ans, GetScore(comp1, comp2, comp3));
                }
                else if (is_ancestor[c2][c1]) {
                    int comp1 = subtree_xor[c1];
                    int comp2 = subtree_xor[c1] ^ subtree_xor[c2];
                    int comp3 = subtree_xor[0] ^ comp1 ^ comp2;
                    
                    ans = min (ans, GetScore(comp1, comp2, comp3));
                }
                else {
                    int comp1 = subtree_xor[c2];
                    int comp2 = subtree_xor[c1];
                    int comp3 = subtree_xor[0] ^ comp1 ^ comp2;
                    
                    ans = min (ans, GetScore(comp1, comp2, comp3));
                }
            }
        }
        
        return ans;
    }
};