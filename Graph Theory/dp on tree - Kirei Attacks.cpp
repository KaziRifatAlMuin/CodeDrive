#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <vector<ll>> G;
vector <ll> dp, val;

void dfs(ll u, ll par = -1){
    // par - 0th level
    // u - 1st level
    for(auto v : G[u]){
        // v - 2nd level
        if(v == par) continue;
        if(par != -1){
            dp[v] = max(val[v], val[v] + dp[par] - val[u]);
            // cout << v << " " << val[v] + dp[par] - val[u] << "\n";
        }
        else{
            dp[v] = val[v];
            // cout << v << "H\n";
        }
        dfs(v, u);
    }
}

void solve() {
    ll n;
    cin >> n;
    dp.assign(n+1, 0);
    val.assign(n+1, 0);
    G.assign(n+1, {});
    for(int i = 1; i <= n; i++) cin >> val[i];
    dp[1] = val[1];
    // for(int i = 1; i <= n; i++) cout << val[i] << " ";
    // cout << "\n";
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
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
// https://codeforces.com/contest/2114/problem/E