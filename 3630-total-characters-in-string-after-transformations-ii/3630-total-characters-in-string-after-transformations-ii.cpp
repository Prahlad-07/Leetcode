class Solution {
    const int mod = 1e9 + 7;

public:
    int lengthAfterTransformations(string s, int t, vector<int>& cp) {
        if(t == 0) return s.length() % mod;
        
        vector<long long> boy(26, 0);
        for(char ch : s) boy[ch - 'a']++;

        vector<vector<long long>> m(26, vector<long long>(26, 0));
        for(int i=0; i<26; i++) {
            int v = cp[i];
            for(int j=1; j<=v; j++) {
                m[i][(i + j) % 26] = 1;
            }
        }

        vector<vector<long long>> mt = powerMatrix(m, t);

        vector<long long> sum(26, 0);
        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                sum[i] = (sum[i] + mt[i][j]) % mod;
            }
        }

        long long ans = 0;
        for(int i=0; i<26; i++) {
            ans = (ans + boy[i] * sum[i] % mod) % mod;
        }
        return ans;
    }

private:
    vector<vector<long long>> powerMatrix(vector<vector<long long>>& base, int exp) {
        vector<vector<long long>> res(26, vector<long long>(26, 0));
        for(int i=0; i<26; i++) res[i][i] = 1;

        while(exp > 0) {
            if(exp & 1) res = mul(res, base);
            base = mul(base, base);
            exp >>= 1;
        }
        return res;
    }

    vector<vector<long long>> mul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        vector<vector<long long>> c(26, vector<long long>(26, 0));
        for(int i=0; i<26; i++) {
            for(int k=0; k<26; k++) {
                if(a[i][k]) {
                    for(int j=0; j<26; j++) {
                        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                    }
                }
            }
        }
        return c;
    }
};
