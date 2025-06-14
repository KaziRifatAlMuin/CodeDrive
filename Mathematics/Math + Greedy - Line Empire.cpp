#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector <ll> v(n), pre(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pre[i+1] = pre[i] + v[i];
    }
    ll ans = pre[n] * b;
    // Final capital at i-th posithoin
    // If I conquer and instantly make it capital, it is optimal
    // a * ((c3-c2) + (c2-c1)) = a * (c3-c1) ie moving capital to ci from 0 is always same
    // Thus shifting capital at every step just lessens cost of conquering
    for(int i = 1; i <= n; i++){
        ll cost = (b * (pre[n] - pre[i] - (n-i) * v[i-1])) + (a+b) * v[i-1];
        ans = min(ans, cost);
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
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1659/C