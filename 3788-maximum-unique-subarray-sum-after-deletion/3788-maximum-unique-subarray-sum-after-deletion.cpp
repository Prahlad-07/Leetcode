class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        set<int>st;
        int maxi = INT_MIN;
        int cnt = 0;
        for(auto &val : nums){
            if(st.find(val) == st.end()){
                st.insert(val);
                if(val >= 0){
                    sum += val;
                }
            }
            maxi = max(maxi , val);
            if(val < 0) cnt++;
        }
        if(cnt == nums.size()) return maxi;
        return sum;       
        
    }
};