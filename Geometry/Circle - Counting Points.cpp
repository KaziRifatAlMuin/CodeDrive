#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <ll> xx(n), rr(n);
    for(int i = 0; i < n; i++) cin >> xx[i];
    for(int i = 0; i < n; i++) cin >> rr[i];
    vector <pair<ll,ll>> xr;
    map <ll,ll> mp;
    for(int i = 0; i < n; i++){
        xr.push_back({xx[i], rr[i]});
    }
    sort(xr.begin(), xr.end());
    ll ans = 0;
    for(auto [xi, r] : xr){
        for(ll dx = -r; dx <= r; dx++){
            ll dy2 = r * r - dx * dx;
            if(dy2 < 0) continue;
            ll dy = (double) sqrt(dy2);
            if(mp.find(xi + dx) == mp.end()) mp[xi+dx] = dy;
            else mp[xi+dx] = max(mp[xi+dx], dy);
        }
    }
    for(auto [xi, y] : mp){
        ans += (2 * y + 1);
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
// https://codeforces.com/contest/2074/problem/D