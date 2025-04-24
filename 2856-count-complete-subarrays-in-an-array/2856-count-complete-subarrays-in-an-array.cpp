class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int>st(nums.begin(),nums.end());
        int all=st.size();
        int cnt=0;
        st.clear();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                if(st.size()==all){
                    cnt++;
                }

            }
            st.clear();
        }

        return cnt;
        
    }
};