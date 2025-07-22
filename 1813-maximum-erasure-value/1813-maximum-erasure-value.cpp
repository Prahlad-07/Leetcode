class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>mp;
        int maxi = 0;
        int sum = 0;
        int i = 0, j = 0;
        int n =  nums.size();
        while(j < nums.size()) {
            sum+= nums[j];
            mp[nums[j]]++;
            while(mp[nums[j]]>1){
                mp[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            maxi = max(maxi, sum);
            j++;
        } 

        return maxi;
        
    }
};