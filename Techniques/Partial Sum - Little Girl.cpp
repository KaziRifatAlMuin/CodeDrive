#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector <ll> v(n), cnt(n+1), pre(n+1);
    for(int i = 0; i < n; i++) cin >> v[i];
    while(q--){
        ll l, r;
        cin >> l >> r;
        cnt[l-1]++; cnt[r]--;
    }
    for(int i = 0; i < n; i++){
        pre[i+1] = pre[i] + cnt[i];
    }
    sort(pre.rbegin(), pre.rend());
    sort(v.rbegin(), v.rend());
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += (v[i] * pre[i]);
    }
    cout << sum << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}