class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        int idx=0;
        int n=s.size();
        vector<string>ans;
        while(idx<n){
            if(idx+k>=n){
                string temp;
                while(idx<n){
                    temp+=s[idx];
                    idx++;
                }
                while(temp.size()<k){
                    temp+=fill;
                }
                ans.push_back(temp);
            }
            else{
                string temp=s.substr(idx,k);
                ans.push_back(temp);

            }
            idx+=k;
        }
        return ans;
    }
};
