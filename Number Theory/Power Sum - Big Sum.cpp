#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

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

inline ll modInverse(ll a) { return power(a, mod - 2); }

ll formula(ll a, ll n){
    if(a == 1) return n;
    return ((power(a, n) - 1) * (modInverse(a - 1))) % mod; // if mod is prime
}

void solve() {
    ll i1, i2, j1, j2;
    cin >> i1 >> i2 >> j1 >> j2;
    ll mul1 = (((formula(2, i2+1) - formula(2, i1)) % mod) + mod) % mod;
    ll mul2 = (((formula(3, j2+1) - formula(3, j1)) % mod) + mod) % mod;
    // cout << mul1 << " " << mul2 << "\n";
    cout << (mul1 * mul2) % mod << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/gym/102862/problem/M