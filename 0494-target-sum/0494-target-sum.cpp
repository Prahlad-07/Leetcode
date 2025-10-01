class Solution {
    int dp[101][2001];
    int solve(vector<int>&nums, int idx, int n, int target, int sum){
        if(idx >= n){
            return sum == target ? 1 : 0;
        }
        if(dp[idx][sum + 1000] != -1)return dp[idx][sum + 1000];
        int plus = solve(nums, idx + 1, n, target, sum + nums[idx]);
        int minus = solve(nums, idx + 1, n, target, sum - nums[idx]);
        return dp[idx][sum + 1000] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, n, target, 0);
    }
};