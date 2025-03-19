#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <pair<int,int>> segs;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        segs.push_back({x,y});
    }
    int q; cin >> q;
    vector <int> a(q);
    for(int i = 0; i < q; i++) cin >> a[i];
    int low = 0, high = q - 1, ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        vector <int> v(n), pre(n+1);
        for(int i = 0; i <= mid; i++) v[a[i]-1] = 1;
        for(int i = 0; i < n; i++) pre[i+1] = pre[i] + v[i];
        bool ok = false; // FFFFFTTTTT
        for(auto [l,r] : segs){
            if(pre[r] - pre[l-1] > ((r - l + 1) / 2)) ok = true;
        }
        if(ok) ans = mid + 1, high = mid - 1;
        else low = mid + 1;
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
// https://codeforces.com/problemset/problem/1843/E