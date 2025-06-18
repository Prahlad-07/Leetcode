class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
       vector<vector<int>>ans;
       int left=0;
       int right=2;
       int n=nums.size();
       sort(nums.begin(),nums.end());
       while(right<n){
        int diff=nums[right]-nums[left];
        if(diff<=k){
            ans.push_back({nums[left],nums[left+1],nums[right]});
            left+=3;
            right+=3;
        }
        else{
            return {};
        }
       }

       return ans;
        
    }
};