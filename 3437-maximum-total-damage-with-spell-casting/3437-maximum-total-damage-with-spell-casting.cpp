class Solution {
    // // map<int,long long> mp;
    // // vector<long long> dp;
    // long long solve(vector<long long>& arr, int idx, int n){
    //     if(idx >= n){
    //         return 0;
    //     }
    //     if(dp[idx] != -1) return dp[idx];
    //     auto it = lower_bound(arr.begin(), arr.end(), arr[idx] + 3);
    //     long long op1 = arr[idx] * mp[arr[idx]] * 1LL + solve(arr, it, n);
    //     long long op2 = solve(arr, idx + 1, n);
    //     return dp[idx] = max(op1, op2);
    // }
public:
    long long maximumTotalDamage(vector<int>& power) {
        // for (int x : power) mp[x]++;
        // vector<long long> val;
        // for (auto &[k,v] : mp) val.push_back(k);
        // int m = val.size();
        // sort(val.begin(), val.end());
        // dp.resize(m + 1, -1);
        // dp[0] = val[0] * mp[val[0]];
        // for (int i = 1; i < m; i++) {
        //     long long pick = val[i] * mp[val[i]];
        //     if (val[i] == val[i - 1] + 1) {
        //         pick += (i > 1 ? dp[i - 2] : 0);
        //         dp[i] = max(dp[i - 1], pick);
        //     } else {
        //         pick += dp[i - 1];
        //         dp[i] = pick;
        //     }
        // }
        // return dp[m - 1];
        // return solve(val, 0 , m);
        map<int,long long> mp;
        for (int x : power) mp[x]++;

        vector<long long> val;
        for (auto &[k,v] : mp) val.push_back(k);
        int n = val.size();

        vector<long long> dp(n, 0);
        dp[0] = val[0] * mp[val[0]];

        for (int i = 1; i < n; i++) {
            long long pick = val[i] * mp[val[i]];
            int j = upper_bound(val.begin(), val.end(), val[i] - 3) - val.begin() - 1;
            if (j >= 0) pick += dp[j];
            long long notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};
