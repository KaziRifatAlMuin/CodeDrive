#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Goal: GCD(a[0]+b[j], a[1]+b[j], ..., a[n-1]+b[j])
// Property : GCD(P, Q) = GCD(P, Q - P)
// General: GCD(P, Q, R, ...) = GCD(P, Q-P, R-P, ...)

// Applying this, terms become:
// 1. a[0]+b[j] (first term, P)
// 2. (a[1]+b[j]) - (a[0]+b[j]) = a[1]-a[0]  (Q-P)
// 3. (a[2]+b[j]) - (a[0]+b[j]) = a[2]-a[0]  (R-P)
// ... and so on for all a[i] where i > 0.

// Precompute: remGCD = GCD(a[1]-a[0], a[2]-a[0], ..., a[n-1]-a[0])
// Final answer for each b[j]: GCD(a[0]+b[j], remGCD)

void solve(){
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    ll remGCD = 0;
    for(int i = 1; i < n; i++) remGCD = __gcd(remGCD, abs(a[i] - a[0])); // abs to take always +ve
    for(int j = 0; j < m; j++) cout << __gcd(a[0] + b[j], remGCD) << " ";
    cout << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1458/problem/A