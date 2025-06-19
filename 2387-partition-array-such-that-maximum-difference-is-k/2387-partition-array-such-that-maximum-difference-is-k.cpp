class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0,right=0;
        while(right<n){
            while(right<n && (nums[right]-nums[left])<=k){
                right++;
            }
            left=right;
            cnt++;

        }
        return cnt;
        
    }
};