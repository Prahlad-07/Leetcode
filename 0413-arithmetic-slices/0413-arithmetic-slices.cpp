class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]-nums[i-1]==nums[i+1]-nums[i]){
                dp[i]=dp[i-1]+1;
                cnt+=dp[i];
            }
        }
        return cnt;
        
    }
};