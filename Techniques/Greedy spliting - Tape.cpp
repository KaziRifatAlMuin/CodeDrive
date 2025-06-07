#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> v(n), gap;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) gap.push_back(v[i] - v[i-1] - 1);
    ll all = v[n-1] - v[0] + 1;
    // k = 1 : can remove no gaps
    // k = 2 : can remove 1 gaps by spliting the tape there
    // k = 3 : can remove 2 gaps by spliting the tape in those 2 section
    // In general, it is optimal to remove largest k-1 gaps
    sort(gap.rbegin(), gap.rend());
    ll ans = all;
    for(int i = 0; i < k - 1; i++) ans -= gap[i];
    cout << ans << "\n";
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
// https://codeforces.com/problemset/problem/1110/B