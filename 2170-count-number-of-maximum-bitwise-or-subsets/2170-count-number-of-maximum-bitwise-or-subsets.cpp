class Solution {
private:
    vector<vector<int>> solve(const vector<int>& a) {
        int n = a.size(), t = 1 << n;
        vector<vector<int>> r;
        for (int m = 0; m < t; ++m) {
            vector<int> s;
            for (int i = 0; i < n; ++i)
                if (m & (1 << i)) s.push_back(a[i]);
            r.push_back(s);
        }
        return r;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> subset = solve(nums);
        vector<int> orArray;
        for (int i = 0; i < subset.size(); i++) {
            int x = 0;
            for (int j = 0; j < subset[i].size(); j++) x |= subset[i][j];
            orArray.push_back(x);
        }
        int maxi = *max_element(orArray.begin(), orArray.end());
        int cnt = count(orArray.begin(), orArray.end(), maxi);
        return cnt;
    }
};