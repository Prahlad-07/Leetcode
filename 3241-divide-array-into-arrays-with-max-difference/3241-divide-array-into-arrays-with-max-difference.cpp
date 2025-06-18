class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = 2;

        while (right < n) {
            int diff = nums[right] - nums[left];
            if (diff <= k) {
                ans.push_back({nums[left], nums[left + 1], nums[right]});
                left += 3;
                right += 3;
            } else {
               
                return {};
            }
        }

        return ans;
    }
};
