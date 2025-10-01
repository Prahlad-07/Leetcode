class Solution {
    int solve(vector<int>&nums, int idx, int n, int target, int sum){
        if(idx >= n){
            return sum == target ? 1 : 0;
        }
        
        int plus = solve(nums, idx + 1, n, target, sum + nums[idx]);
        int minus = solve(nums, idx + 1, n, target, sum - nums[idx]);
        return plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, 0, n, target, 0);
    }
};