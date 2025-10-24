class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> st;              
        queue<string> q;
        string ans = s;
        q.push(s);
        st.insert(s);                

        while (!q.empty()) {
            string str = q.front();   
            q.pop();
            ans = min(ans, str);

            string t = str;
            for (int i = 1; i < t.size(); i += 2) {
                t[i] = ((t[i] - '0' + a) % 10) + '0';
            }
            if (!st.count(t)) {
                st.insert(t);
                q.push(t);
            }

            string rotated = str.substr(str.size() - b) + str.substr(0, str.size() - b);
            if (!st.count(rotated)) {
                st.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }
};
