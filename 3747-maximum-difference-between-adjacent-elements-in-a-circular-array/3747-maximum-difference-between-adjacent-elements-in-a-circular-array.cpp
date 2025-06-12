class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxi=abs(nums[n-1]-nums[0]);
        for(int i=1;i<nums.size();i++){
            int val=abs(nums[i]-nums[i-1]);
            maxi=max(maxi,val);
        }
        return maxi;
        
    }
};