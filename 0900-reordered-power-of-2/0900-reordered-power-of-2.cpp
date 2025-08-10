class Solution {
    vector<string> comb(string s, int k) {
        vector<string> r; string t;
        function<void(int,int)> dfs = [&](int st, int l) {
            if(!l) { r.push_back(t); return; }
            for(int i = st; i <= s.size()-l; i++) {
                t.push_back(s[i]);
                dfs(i+1, l-1);
                t.pop_back();
            }
        };
        dfs(0, k);
        return r;
    }
    bool pow2(long long x) {
        return x > 0 && !(x & (x - 1));
    }
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        do {
            if(s[0] != '0' && pow2(stoll(s))) return true;
        } while(next_permutation(s.begin(), s.end()));
        return false;
    }
};
