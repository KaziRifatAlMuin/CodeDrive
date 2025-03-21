#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, lim; 
    cin >> n >> lim;
    vector <pair<ll,ll>> v;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll l = 0; l < n; l++){
        priority_queue <ll> q;
        ll cur = 0;
        for(ll r = l; r < n; r++){
            q.push(v[r].second);
            cur += v[r].second;
            while(!q.empty() && cur + (v[r].first - v[l].first) > lim){
                cur -= q.top();
                q.pop();
            }
            ans = max(ans, (ll) q.size());
        }
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
// https://codeforces.com/contest/1935/problem/C