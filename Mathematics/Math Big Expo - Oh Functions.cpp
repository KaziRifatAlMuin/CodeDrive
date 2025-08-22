#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007LL;

static inline ll mulmod(ll a, ll b, ll m) {
    a %= m; b %= m;
    return (ll)((__int128)a * b % m);
}

ll powmod(ll a, long long b, ll m) {
    a %= m;
    if (a < 0) a += m;
    ll res = 1 % m;
    while (b > 0) {
        if (b & 1) res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        b >>= 1;
    }
    return res;
}

ll modMul(ll a, ll b) { return mulmod(a, b, mod); }
ll modAdd(ll a, ll b) { return ( (a%mod) + (b%mod) ) % mod; }
ll modSub(ll a, ll b) { return ( (a%mod) - (b%mod) + mod ) % mod; }
ll modInverse(ll a)   { return powmod((a%mod+mod)%mod, mod-2, mod); }
ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

// sum(a, n) = 1 + a + a^2 + ... + a^(n-1) (mod mod)
ll sum(ll a, long long n){
    if (n == 0) return 0;
    a %= mod;
    if (a < 0) a += mod;
    if (a == 1) return n % mod;
    ll up = modSub(powmod(a, n, mod), 1);
    ll down = modSub(a, 1);
    return modDiv(up, down);
}

void solve() {
    long long n; 
    cin >> n;

    // Exponents reduced modulo (mod-1)
    ll p  = (powmod(2, n+1, mod-1) - 1 + (mod-1)) % (mod-1);
    ll pp = (powmod(2, n,   mod-1) - 1 + (mod-1)) % (mod-1);

    ll h  = powmod(3, p,  mod);            // 3^(2^(n+1)-1) mod mod
    ll hh = powmod(3, pp, mod);            // 3^(2^n - 1)   mod mod
    hh = modMul(hh, hh);                   // 3^(2*(2^n -1)) = 3^(2^(n+1)-2)

    ll mul = modMul(14, sum(12, n));       // 14 * ((12^n - 1)/11)
    hh = modSub(hh, mul);                  // hh = 3^(2^(n+1)-2) - 14*sum

    // a = (h + hh)/2 , b = (h - hh)/2  (mod mod)
    ll a = modDiv(modAdd(h, hh), 2);
    ll b = modDiv(modSub(h, hh), 2);

    cout << a << " " << b << "\n";
}
   
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, cs = 1, st = clock();
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/problem/Toph-oh-functions