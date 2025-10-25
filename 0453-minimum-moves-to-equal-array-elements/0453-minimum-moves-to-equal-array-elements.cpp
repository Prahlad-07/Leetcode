class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin (), nums.end());
        int cost = 0;
        for(auto &val : nums){
            cost += (val - mini);
        }
        return cost;
        
    }
};