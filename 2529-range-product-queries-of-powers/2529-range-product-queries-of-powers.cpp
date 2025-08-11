class Solution {
    const int mod = 1e9 + 7;
private:
    vector<int> powersOfTwoFromN(int n) {
        vector<int> res;
        int power = 1;
        while (n > 0) {
            if (n & 1) res.push_back(power);
            power <<= 1;
            n >>= 1;
        }
        return res;
    }

    long long modPow(long long b, long long e, long long m) {
        long long r = 1;
        b %= m;
        while (e) {
            if (e & 1) r = (r * b) % m;
            b = (b * b) % m;
            e >>= 1;
        }
        return r;
    }

    long long modInverse(long long a, long long m) {
        return modPow(a, m - 2, m);
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int> p = powersOfTwoFromN(n);
        int N = q.size();
        vector<long long> pref(p.size() + 1, 1);
        for (int i = 0; i < (int)p.size(); i++) pref[i + 1] = (pref[i] * p[i]) % mod;

        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            int l = q[i][0], r = q[i][1];
            long long num = pref[r + 1];
            long long den = pref[l];
            long long inv = modInverse(den, mod);
            ans[i] = (num * inv) % mod;
        }
        return ans;
    }
};
