class Solution {
public:
    int countSubarrays(vector<int>& nums) {
         int cnt=0;
         for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(j-i+1==3 && nums[i]+nums[j]==float(nums[i+1]/2.0))cnt++;
            }
         }
         return cnt;
        
    }
};