#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7, mod = 1e9 + 7;

ll fact[N];

void pre(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++) fact[i] = (i * fact[i-1]) % mod;
}

// To be Good: AND_pref[i] = AND_suf[i+1] for all i from 1 to n-1.
// This chain of equalities implies all AND_pref[i] and AND_suf[i] are equal.
// Hence, entire sequence's AND at every split point must match a fixed value.
// That value is x = a1 & a2 & ... & an (total AND).
// At least two elements must be exactly x to place at ends.
// Remaining elements must be supermasks of x: (a & x == x).
// If less than 2 x's → answer is 0; else → cnt * (cnt - 1) * (n - 2)! % mod.

void solve(){
    int n; cin >> n;
    vector <ll> v(n);
    ll x, cnt = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    x = v[0];
    for(int i = 0; i < n; i++) x &= v[i];
    for(int i = 0; i < n; i++){
        if(v[i] == x) cnt++;
    }
    ll ans = 0;
    if(cnt >= 2){
        ans =(((cnt * (cnt - 1)) % mod) * fact[n-2]) % mod;
    }
    cout << ans << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1513/B