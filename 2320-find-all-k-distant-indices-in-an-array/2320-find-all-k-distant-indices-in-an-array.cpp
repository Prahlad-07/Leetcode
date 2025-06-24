class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] == key && abs(i-j) <= k){
                    ans.push_back(i);
                    break;
                } 
            }
        }
        return ans;
    }
};