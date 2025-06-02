#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector <int> v(n);
    map <ll, ll> mp;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i] - i] += v[i];
    }
    ll ans = 0;
    for(auto [x, y] : mp){
        ans = max(ans, y);
    }
    cout << ans << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1320/A