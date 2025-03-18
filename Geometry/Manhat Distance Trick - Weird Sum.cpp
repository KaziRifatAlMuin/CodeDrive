#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector <pair<int,int>> v[N];

void solve() {
    int n, m;
    cin >> n >> m;
    set <int> colors;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int c; cin >> c;
            v[c].push_back({i,j});
            colors.insert(c);
        }
    }
    ll ans = 0;
    for(auto col : colors){
        vector <ll> xx, yy;
        for(auto [x,y] : v[col]){
            xx.push_back(x);
            yy.push_back(y);
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        ll sum_x = 0, sum_y = 0;
        int sz = xx.size();
        for(int i = 0; i < sz; i++) {
            sum_x += 1LL * xx[i] * (2 * i - sz + 1);
            sum_y += 1LL * yy[i] * (2 * i - sz + 1);
        }
        // contribution of ith element = (-n+1) + 2*i
        // cause minus decrease, and plus increases by one each time
        ans += sum_x + sum_y;
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
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1648/problem/A