class Solution {
set<char>st;

bool check(string &s){
    for(auto &ch : s){
        if(st.find(ch) != st.end())return false;
    }
    return true;
}
public:
    int canBeTypedWords(string text, string brokenLetters) {
        for(auto &ch : brokenLetters)st.insert(ch);
        int idx = 0;
        int cnt = 0;
        while(idx < text.size()){
            string temp = "";
            while(idx < text.size() && text[idx] != ' '){
                temp += text[idx];
                idx++;
            }

            if(check(temp)) cnt++;
            idx++;
        }

        return cnt;
        
    }
};