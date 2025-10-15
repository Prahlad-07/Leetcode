class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        vector<int> all;
        int i = 0;

        for (int j = 1; j < n; ++j) {
            if (nums[j] <= nums[j - 1]) {
                all.push_back(j - i);
                i = j;
            }
        }

        all.push_back(n - i); 

        if (all.size() == 1) return all[0] / 2;

        for (auto &x : all) cout << x << " ";
        cout << "\n";

        int ans = 0;
        for (int k = 1; k < all.size(); ++k) {
            int prev = all[k - 1];
            int curr = all[k];
            ans = max(ans, max({min(prev, curr), prev / 2, curr / 2}));
        }

        return ans;
    }
};