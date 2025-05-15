#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5, mod = 998244353;

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return result;
}

int f[N], invf[N], spf[N];

void pre() {
    for(int i = 1; i < N; i++) spf[i] = i;
    for(int i = 2; i * i < N; i++) {
        if(spf[i] == i) { // i is a prime, not marked by its smaller
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    f[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r) {
    if(n < r or n < 0 or r < 0) return 0;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll ans = 0;
    vector <int> cnt(n+1, 0);
    for(auto x : v){
        while(x > 1){
            ll p = spf[x];
            while(x % p == 0) x /= p;
            ll cur = (p * nCr(n - 1 - cnt[p], k - 1)) % mod;
            ans = (ans + cur) % mod;
            cnt[p]++;
        }
    }
    cout << ans % mod << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/gym/105884/problem/J