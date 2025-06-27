class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto &val :nums)
        {
            if(st.find(val)!=st.end())return val;
            st.insert(val);
        }
        return 0;
    }
};