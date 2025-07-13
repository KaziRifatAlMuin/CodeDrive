#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n+1), ans(n+1);
    vector <pair<ll,ll>> vv;
    for(int i = 1; i <= n; i++) cin >> v[i], vv.push_back({v[i], i});
    sort(vv.begin(), vv.end());
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += (vv[i].first - vv[0].first + 1);
    }
    ans[vv[0].second] = sum;
    for(int i = 1; i < n; i++){
        sum -= ((n-i) * (vv[i].first - vv[i-1].first)); // contri off
        sum += (i * (vv[i].first - vv[i-1].first)); // contri on
        ans[vv[i].second] = sum;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
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
// https://codeforces.com/problemset/problem/1857/E