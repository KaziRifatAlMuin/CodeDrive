#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll run(ll l1, ll r1, ll l2, ll r2, ll x){
    if(l1 == r1 || l2 == r2 || x == 0) return 0;
    ll a = l1 % x == 0 ? l1 : (l1 / x) * x + x;
    ll b = (r1 / x) * x;
    ll c = l2 % x == 0 ? l2 : (l2 / x) * x + x;
    ll d = (r2 / x) * x;
    if(a >= b || c >= d) return run(l1, r1, l2, r2, x/2); // If invalid with current x, go smaller
    return (((b - a) / x) * ((d - c) / x))
    + run(l1, a, l2, c, x/2) + run(a, b, l2, c, x/2) 
    + run(b, r1, l2, c, x/2) + run(b, r1, c, d, x/2) 
    + run(b, r1, d, r2, x/2) + run(a, b, d, r2, x/2) 
    + run(l1, a, d, r2, x/2) + run(l1, a, c, d, x/2); 
}

void solve() {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll x = 1 << 20;
    cout << run(l1, r1, l2, r2, x) << "\n";
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
// https://codeforces.com/contest/2074/problem/F