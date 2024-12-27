#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    set <ll> c;
    for(int i = 0; i < n; i++) cin >> a[i], c.insert(a[i]);
    for(int i = 0; i < n; i++) cin >> b[i], c.insert(b[i]);
    ll ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(auto x : c){
        auto sale = n - (lower_bound(b.begin(), b.end(), x) - b.begin());
        auto pos = n - (lower_bound(a.begin(), a.end(), x) - a.begin());
        if(sale - pos <= k) ans = max(ans, x * sale);
        // cout << x << ": " << sale << " " << sale - pos << " " << ans << " " << x * sale << "\n";
    }
    cout << ans << "\n";
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
// https://codeforces.com/contest/2051/problem/E