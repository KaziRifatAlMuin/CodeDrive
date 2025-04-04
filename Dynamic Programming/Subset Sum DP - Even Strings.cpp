#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
const int MOD = 998244353;

template<const int &MOD>
struct _m_int {
    int val;
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
    _m_int& operator+=(const _m_int &other) { val -= MOD - other.val-(val-MOD+other.val<0?MOD:0);return *this;}
    _m_int& operator-=(const _m_int &other) { val-=other.val-(val-other.val<0?MOD:0); return *this;}
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
    _m_int& operator*=(const _m_int &other) { val = fast_mod(uint64_t(val) * other.val); return *this;}
    _m_int& operator/=(const _m_int &other) { return *this *= other.inv();}
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
    _m_int& operator++() {val = val == MOD - 1 ? 0 : val + 1;return *this;}
    _m_int& operator--() {val = val == 0 ? MOD - 1 : val - 1;return *this;}
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
    _m_int operator-() const { return val == 0 ? 0 : MOD - val;}
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];
    static void prepare_inv() {
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1) assert(MOD % p != 0);
        save_inv[0] = 0, save_inv[1] = 1;
        for (int i = 2; i < SAVE_INV; i++) save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }
    _m_int inv() const {
        if (save_inv[1] == 0)prepare_inv();
        if (val < SAVE_INV)return save_inv[val];
        _m_int product = 1;
        int v = val;
        do {
            product *= MOD - MOD / v, v = MOD % v;
        } while (v >= SAVE_INV);
        return product * save_inv[v];
    }
    _m_int pow(int64_t p) const {
        if (p < 0) return inv().pow(-p);
        _m_int a = *this, result = 1;
        while (p > 0) {
            if (p & 1) result *= a;
            p >>= 1;
            if (p > 0) a *= a;
        }
        return result;
    }
    friend ostream& operator<<(ostream &os, const _m_int &m) { return os << m.val;}
};
template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
template<const int &MOD>
struct combinatorics {
    using combo_int = _m_int<MOD>;
    vector<combo_int> _factorial = {1}, _inv_factorial = {1};
    void prepare_factorials(int64_t maximum) {
        static int64_t prepared_maximum = 0;
        if (maximum <= prepared_maximum)
            return;
        maximum = max(maximum, int64_t(1.01L * prepared_maximum));
        _factorial.resize(maximum + 1);
        _inv_factorial.resize(maximum + 1);
        for (int64_t i = prepared_maximum + 1; i <= maximum; i++)
            _factorial[i] = i * _factorial[i - 1];
        _inv_factorial[maximum] = _factorial[maximum].inv();
        for (int64_t i = maximum - 1; i > prepared_maximum; i--)
            _inv_factorial[i] = (i + 1) * _inv_factorial[i + 1];
        prepared_maximum = maximum;
    }
    combo_int factorial(int64_t n) {
        if (n < 0) return 0;
        prepare_factorials(n);
        return _factorial[n];
    }
    combo_int inv_factorial(int64_t n) {
        if (n < 0) return 0;
        prepare_factorials(n);
        return _inv_factorial[n];
    }
    combo_int choose(int64_t n, int64_t r) {
        if (r < 0 || r > n) return 0;
        prepare_factorials(n);
        return _factorial[n] * _inv_factorial[r] * _inv_factorial[n - r];
    }
    combo_int permute(int64_t n, int64_t r) {
        if (r < 0 || r > n) return 0;
        prepare_factorials(n);
        return _factorial[n] * _inv_factorial[n - r];
    }
    combo_int inv_choose(int64_t n, int64_t r) {
        assert(0 <= r && r <= n);
        prepare_factorials(n);
        return _inv_factorial[n] * _factorial[r] * _factorial[n - r];
    }
    combo_int inv_permute(int64_t n, int64_t r) {
        assert(0 <= r && r <= n);
        prepare_factorials(n);
        return _inv_factorial[n] * _factorial[n - r];
    }
};

using mod_int = _m_int<MOD>;
combinatorics<MOD> combo;

void solve() {
    ll n = 0;
    vector <ll> v;
    ll maxi = 0;
    mod_int ans = 1;
    for(int i = 0; i < 26; i++){
        ll b; cin >> b;
        if(b > 0) v.push_back(b);
        n += b;
    }
    ll k = n/2; // number of even
    ans *= combo.factorial(k);
    ans *= ans;
    if(n & 1) ans *= (k+1);
    vector <mod_int> dp(k+1, 0);
    dp[0] = 1;
    for(auto x : v){
        for(int i = k; i >= x; i--){
            dp[i] += dp[i-x];
        }
        ans /= combo.factorial(x);
    }
    ans *= dp[k]; // number of ways to get sum k with some x of v
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2086/problem/D