class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt=0;
        long long i=0, j=0, n=nums.size();
        long long sum=0;
        while(j<n){ 
            sum+=nums[j];
            while(sum*(j-i+1)>=k){
                sum-=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};
