int mod = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftOptions;
        vector<int> rightOptions;
        stack<pair<int, int>> st;

        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }
            leftOptions.push_back((st.empty() 
                ? i + 1 
                : i - st.top().second)
            );
            st.push({arr[i], i});
        }

        while(!st.empty()) st.pop();

        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top().first > arr[i]) {
                st.pop();
            }
            rightOptions.push_back((st.empty() 
                ? n - i 
                : st.top().second - i)
            );
            st.push({arr[i], i});
        }
        reverse(rightOptions.begin(), rightOptions.end());
        
        

        long long res = 0;
        for(int i = 0; i < arr.size(); i++) {
            long long curr = 
                (1ll * leftOptions[i] * rightOptions[i] * arr[i]) % mod;
            res = (res + curr) % mod;
        }
        return (int)res;
    }
};