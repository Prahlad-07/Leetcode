class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto &val : arr) mp[val]++;
        vector<pair<int,int>>p;
        for(auto [val, freq] : mp){
            p.push_back({freq, val});
        }
        sort(p.begin(), p.end());
        int cnt = mp.size();
        for(int i = 0; i < p.size(); i++){
            int freq = p[i].first;
            if(freq  <= k){
                k -= (freq );
                cnt--;
            }
        }
        return cnt;
    }
};