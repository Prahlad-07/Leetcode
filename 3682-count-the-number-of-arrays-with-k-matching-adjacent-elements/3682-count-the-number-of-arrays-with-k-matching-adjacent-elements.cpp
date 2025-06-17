#define MOD 1000000007
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i >= b; i--)
#define powr(a, b) power_pow(a, b)
#define fact_arr(n) fact_calc(n)
#define inv_arr(n) inv_calc(n)
#define C(n, k) (fact_arr(n)[(n)-1] * inv_arr(n)[(k)] % MOD * inv_arr(n)[(n)-1-(k)] % MOD)
#define mp(x, y) ((x) * (y) % MOD)


class Solution {
private:
ll power_pow(ll a, ll b) {
    ll r = 1;
    a %= MOD;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

vector<ll> fact_calc(int n) {
    vector<ll> f(n, 1);
    rep(i, 1, n) f[i] = f[i - 1] * i % MOD;
    return f;
}

vector<ll> inv_calc(int n) {
    vector<ll> i(n, 1);
    i[n - 1] = power_pow(fact_arr(n)[n - 1], MOD - 2);
    rrep(j, n - 2, 0) i[j] = i[j + 1] * (j + 1) % MOD;
    return i;
}

public:
    int countGoodArrays(int n, int m, int k) {
       
ll Cnk = C(n, k);
 if (k > n - 1) return 0;
        ll pwr = powr(m - 1, n - 1 - k);
        return mp(Cnk, mp(m, pwr));
    }
};