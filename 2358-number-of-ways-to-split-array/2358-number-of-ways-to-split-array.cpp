class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        for (int i=1;i<n;i++) {
            pref[i]=nums[i]+pref[i-1];
        }
        int cnt=0;
        for (int i=0;i<n-1;i++) {
            if (pref[i]>=(pref[n-1]-pref[i]))cnt++;
        }
        
        return cnt;
    }
};