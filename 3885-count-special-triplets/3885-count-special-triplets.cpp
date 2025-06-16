class Solution {
const int mod = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        map<int, int> total, left;

        for (int x : nums) total[x]++;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            
            total[nums[i]]--; 

            int val = 2 * nums[i];
            int before = left[val];
            int after = total[val];

            if (before > 0 && after > 0) {
                ans = (ans + 1LL * before * after % mod) % mod;
            }

            left[nums[i]]++;
        }

        return ans;
    }
};
