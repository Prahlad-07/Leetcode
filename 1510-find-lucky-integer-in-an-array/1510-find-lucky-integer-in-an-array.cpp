class Solution {
public:
    int findLucky(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    int ans=-1;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==nums[i])
            {
                count++;
            }
        }
        if(count==nums[i])
        {
            ans=nums[i];
            
        }
    
    
       
    }
    return ans;
    }
};