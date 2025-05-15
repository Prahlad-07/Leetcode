class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        set<int>st;
        int n =words.size();
        for(int i=0;i<n;i++){
            if(st.size()==0)
                {
                    st.insert(i);
                    continue;
                    }
                auto idx= *st.rbegin();
                if(groups[i]!=groups[idx]){
                    st.insert(i);
                    }
            
        }
        vector<string>ans;
        for(auto &idx:st)ans.push_back(words[idx]);
        return ans;
        
    }
};
