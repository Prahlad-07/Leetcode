class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
       
        sort(nums.begin(), nums.end());
        set<int>st;
        st.insert(nums[0] - k);
        for(int i = 1; i < n; i++){
            int prev = *st.rbegin();
            int curr = nums[i];
            int next = prev + 1;
            if((next >= nums[i] - k && next <= nums[i] + k) && st.find(next) == st.end()){
                st.insert(next);
            }
            else{
                if(st.find(nums[i] - k) == st.end()){
                    st.insert(nums[i]- k);
                }

            }
        }
        return st.size();
    }
};