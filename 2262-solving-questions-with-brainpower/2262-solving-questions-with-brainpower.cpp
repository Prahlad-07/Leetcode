class Solution {
    vector<long long> dp;

    long long solve(vector<vector<int>>& ques, long long idx, long long n) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        long long take = (long long)ques[idx][0] + solve(ques, idx + (long long)ques[idx][1] + 1, n);
        long long not_take = solve(ques, idx + 1, n);

        return dp[idx] = max(take, not_take);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        dp.assign(n + 1, -1);
        return solve(questions, 0, n);
    }
};