
class Solution {
    vector<vector<int>> dp;
    int n;

    int solve(vector<int>& arr, int idx, bool deleted) {
        if (idx == n) return INT_MIN / 2; 
        if (dp[idx][deleted] != INT_MIN) return dp[idx][deleted];

        int take = arr[idx] + max(0, solve(arr, idx + 1, deleted));
        int del = INT_MIN;
        if (!deleted) del = solve(arr, idx + 1, true);

        return dp[idx][deleted] = max(take, del);
    }

public:
    int maximumSum(vector<int>& arr) {
        n = arr.size();
        /*
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        bool flag = false;
        int sum = 0;

        for (auto &val : arr) {
            if (sum + val >= 0) {
                sum += val;
                maxi = max(maxi, sum);
                cout << val << " -> added, sum=" << sum << ", maxi=" << maxi << "\n";
            } 
            else if (!flag) {
                flag = true;
                cout << val << " -> ignored\n";
            } 
            else {
                sum = 0;
                flag = false;
                cout << val << " -> reset, sum=" << sum << "\n";
            }
        }

        int temp = *max_element(arr.begin(), arr.end());
        if (maxi == 0 && temp != 0) {
            return temp;
        }
        return maxi;
        */
        // dp.assign(n, vector<int>(2, INT_MIN));
        // int ans = INT_MIN;
        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, solve(arr, i, false));
        //     ans = max(ans, solve(arr, i, true));
        // }
        // return ans;

        int dp1 = arr[0];
        int dp2 = -1e9;
        int maxi = arr[0];
        for(int i = 1; i < arr.size(); i++){
            int val = arr[i];
            dp2 = max(dp2 + val, dp1);//dp with at most one deletion
            dp1 = max(val, dp1+val);//reseting the dp;
            maxi = max(maxi, max(dp1, dp2));//calc max of all
            
        }
        return maxi;
        
        
    }
};
