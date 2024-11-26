#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

// abcdabcdabcd -> a..a,b,...d = 8 + 7 + 6 + 5
// power(2, mod - 2) = 499122177

void solve() {
    ll n, k;
    cin >> n >> k;
    ll inc = ((((k - 1) % mod + mod) % mod ) * (n % mod)) % mod;
    ll ex = ((inc % mod - (n) % mod) + mod) % mod;
    ll ans = ((((inc * (inc + 1)) % mod  - (ex * (ex + 1)) % mod) + mod) % mod * 499122177) % mod;
    cout << (k == 1 ? 0 : ans) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/problem/Toph-freezed-standings