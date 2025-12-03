
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll prexor(ll n){
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else return 0;
}

ll func(ll n, ll i, ll k){
    if(n <= 0) return 0;
    ll ans = prexor(n);
    ll x = n >> i; // extract left part
    if(n % (1ll << i) < k) x--;
    ll not_interesting = prexor(x) << i; // adding zeros in right
    if(x % 2 == 0) not_interesting ^= k; // odd number of times as starts with 0
    return ans ^ not_interesting;
}

void solve() {
    ll l, r, i, k;
    cin >> l >> r >> i >> k;
    ll ans = func(r, i, k) ^ func(l-1, i, k);
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
// https://codeforces.com/contest/2036/problem/F