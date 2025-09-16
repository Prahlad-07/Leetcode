class Solution {
    bool isNonCoPrime(long long x, long long y) {
        return __gcd(x, y) > 1;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long val = nums[i];
            while (!st.empty() && isNonCoPrime(st.top(), val)) {
                long long top = st.top();
                st.pop();
                val = (val * top) / __gcd(val, top);
            }
            st.push(val);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
