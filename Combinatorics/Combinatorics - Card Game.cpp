#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod = 998244353;
int const N = 64;

ll win[N], lose[N], total[N];

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (__int128(result) * a) % mod;
        a = (__int128(a) * a) % mod;
        b >>= 1ll;
    }
    return result;
}

ll f[N], invf[N];

void pre1() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
}
int nCr(int n, int r) {
    if (n < r or n < 0) return 0;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}

void pre2() {
    pre1();
    for(int i = 2; i < N; i++) total[i] = nCr(i, i/2) % mod;
    win[2] = 1, win[4] = 3, lose[2] = 0, lose[4] = 2;
    for(int i = 6; i < 64; i += 2){
        win[i] = (lose[i - 2] + nCr(i-1, i/2 - 1)) % mod;
        lose[i] = ((total[i] - win[i] - 1) % mod + mod) % mod;
    }
}

void solve() {
    ll n;
    cin >> n;
    cout << win[n] << " " << lose[n] << " " << 1 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    pre2();
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1739/C