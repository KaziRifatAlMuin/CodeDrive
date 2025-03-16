#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <pair<int,int>> G[N];
vector <int> dp, id;

void dfs(int u){
    for(auto [v, idx] : G[u]){
        if(dp[v] == 0){
            dp[v] = dp[u] + (idx < id[u]);
            id[v] = idx;
            dfs(v);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    dp.assign(n+1, 0);
    id.assign(n+1, 0);
    dp[1] = 1;
    for(int i = 0; i <= n; i++) G[i].clear();
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    dfs(1);
    int ans = 0;
    for(auto x : dp) ans = max(ans, x);
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
// https://codeforces.com/problemset/problem/1830/A