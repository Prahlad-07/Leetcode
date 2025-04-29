class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        long long cnt=0;
        long long ans=0;

        while(j<n){
            if(nums[j]==maxi)cnt++;
            while(cnt>=k){
                ans+=(n-j);
                if(nums[i]==maxi)cnt--;
                i++;
            }
            j++;
            
        }
        
        return ans;
    }
};