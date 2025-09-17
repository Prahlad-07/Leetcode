class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long cnt = 0;
        set<pair<int,int>>st;
        int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         int val1 = nums[i];
        //         int val2 = nums[j];
        //         if(__builtin_popcount(val1 | val2) + __builtin_popcount(val1 & val2) >= k) st.insert({val1, val2});
        //     }
        // }
        // return st.size();


        //Aproach-->
        /*
        use the propety of bit manipulation-->
        Take two numbers num1 and num2. Consider one bit position:

        Case 1: Both bits are 0 →
        (num1 | num2) = 0, (num1 & num2) = 0 → total = 0.
        Same as num1 + num2 = 0.

        Case 2: One bit is 1, the other is 0 →
        (num1 | num2) = 1, (num1 & num2) = 0 → total = 1.
        Same as num1 + num2 = 1.

        Case 3: Both bits are 1 →
        (num1 | num2) = 1, (num1 & num2) = 1 → total = 2.
        Same as num1 + num2 = 2.
        */

        set<int> uniq(nums.begin(), nums.end());
        vector<int>arr;
        for(auto &val : uniq) arr.push_back(__builtin_popcount(val));
        sort(arr.begin(), arr.end()); 
        long long ans = 0;
        int n2 = arr.size();
        for(int i = 0; i < n2; i++){
            int need = k - arr[i];
            if(need <= 0){
                ans += n2;
            }
            else{
                int idx = lower_bound(arr.begin(), arr.end(), need) - arr.begin();
                ans += (n2 - idx);
            }
        }
        return ans;
        
    }
};
