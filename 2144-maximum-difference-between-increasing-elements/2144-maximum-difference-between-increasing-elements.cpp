class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i]-mini;
            if(nums[i]>mini)
            maxi=max(maxi,temp);
            mini=min(mini,nums[i]);
        }
        return maxi;


        
    }
};