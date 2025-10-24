class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string t="";
            for(int i=1;i<s.size();i++){
                int sum=(s[i]-'0')+(s[i-1]-'0');
                t+=sum>=10?to_string(sum-10):to_string(sum);
            }
            s=t;
        }
        return s.size()==2 && s[0]==s[1];
    }
};