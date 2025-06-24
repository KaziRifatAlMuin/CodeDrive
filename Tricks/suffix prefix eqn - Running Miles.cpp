#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e17;

void solve(){
    ll n;
    cin >> n;
    vector <ll> b(n+1), premax(n+2, -inf), sufmax(n+2, -inf);
    for(ll i = 1; i <= n; i++) cin >> b[i];
    ll ans = 0; // bi + bj + bk - (k - i) = (bi + i) + bj + (bk - k)
    for(ll i = 1; i <= n; i++) premax[i] = max(premax[i-1], b[i] + i);
    for(ll i = n; i >= 1; i--) sufmax[i] = max(sufmax[i+1], b[i] - i);
    for(ll j = 2; j < n; j++){
        ll cur = premax[j-1] + b[j] + sufmax[j+1];
        ans = max(ans, cur);
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
// https://codeforces.com/contest/1826/problem/D