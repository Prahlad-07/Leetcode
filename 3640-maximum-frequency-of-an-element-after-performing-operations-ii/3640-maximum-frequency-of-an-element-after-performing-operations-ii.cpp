class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {\
        //line sweeep-->
        map<int,int>mp, freq;
        int n = nums.size();
        for(auto &val : nums){
            freq[val]++;
            int temp = max(0, val - k);
            mp[temp]++;
            mp[val] += 0;
            mp[val + k + 1]--;
        }
        int maxi = 1;
        int line = 0;
        for(auto &[v, f] : mp){
            line += f;
            int p = line - freq[v];
            int x= min(numOperations, p);
            maxi = max(maxi, x + freq[v]);
        }
        return maxi;

    }
};