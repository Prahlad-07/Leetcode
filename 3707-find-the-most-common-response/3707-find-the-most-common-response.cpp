class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string , int>mp;
        for(auto &i:responses) {
            set<string>st;
            for(auto &j:i) st.insert(j);
            for(auto &s:st) mp[s]++;
        }
        int maxi=0;
        for(auto &i:mp)maxi=max(maxi,i.second);
        vector<string>ans;
        for(auto &[str,freq]:mp) 
            if(freq==maxi)ans.push_back(str);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};
