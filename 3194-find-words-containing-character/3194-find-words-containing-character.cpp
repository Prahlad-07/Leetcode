class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int>ans;
        int idx=0;
        for(auto &str:words){
            if (str.find(x) != string::npos)ans.push_back(idx);
            idx++;
        }

        return ans;
        
      
    }
};