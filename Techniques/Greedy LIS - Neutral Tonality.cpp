#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m), c;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b.rbegin(), b.rend());
    int ans = 0, i = 0, j = 0;
    while(c.size() < n+m){
        while(i < n && j < m && b[j] >= a[i]) c.push_back(b[j++]);
        if(i < n) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    for(auto x : c) cout << x << " ";
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
// https://codeforces.com/problemset/problem/1893/B