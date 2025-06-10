class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(auto &i:s){
            mp[i]++;
        }
        vector<int>odd,even;
        for(auto &i:mp){
            if(i.second&1)odd.push_back(i.second);
            else even.push_back(i.second);
        }
        if(odd.empty()||even.empty())return -1;
        int ans=INT_MIN;
        for(auto &o:odd){
            for(auto &e:even){
                ans=max(ans,o-e);
            }
        }
        return ans;
    }
};