class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int>ans(right+1);
        for(auto &val : nums){
            if(val&1){
                ans[right] = val;
                right--;
            }
            else{
                ans[left] = val;
                left++;
            }
        }

        return ans;
        
    }
};