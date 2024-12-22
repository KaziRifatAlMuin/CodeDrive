#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector <ll> a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll mini = sum - y;
    ll maxi = sum - x;
    ll ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        ll low = mini - a[i];
        ll high = maxi - a[i]; 
        auto L = lower_bound(a.begin() + i + 1, a.end(), low);
        auto R = upper_bound(a.begin() + i + 1, a.end(), high);
        ans += (R - L);
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
// https://codeforces.com/contest/2051/problem/D