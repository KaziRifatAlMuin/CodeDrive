#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector <vector <int>> G;
vector <vector<ll>> dp;
vector <int> L, R;

void dfs(int u, int par = -1){
    for(auto v : G[u]){
        if(v == par) continue;
        dfs(v, u);  // FIRST solve child's dp
        // THEN use child's dp to update parent u's dp
        // accumulate into dp[u][0] (when a_u = L[u]):
        dp[u][0] += max(
            dp[v][0] + abs(L[u] - L[v]),   // child picks L[v]
            dp[v][1] + abs(L[u] - R[v])    // child picks R[v]
        );
        // accumulate into dp[u][1] (when a_u = R[u]):
        dp[u][1] += max(
            dp[v][0] + abs(R[u] - L[v]),   // child picks L[v]
            dp[v][1] + abs(R[u] - R[v])    // child picks R[v]
        );
        // Update dp[u] using best from children  
        // assuming a_u is L[u] or R[u]
    }
}

void solve(){
    int n;
    cin >> n;
    G.assign(n+1, {});
    dp.assign(n+1, vector<ll>(2, 0));
    L.assign(n+1, 0);
    R.assign(n+1, 0);
    for(int i = 0; i <= n; i++) G[i].clear();
    for(int i = 1; i <= n; i++) cin >> L[i] >> R[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1); // Choose max beauty if root is L[1] or R[1]
    cout << max(dp[1][0], dp[1][1]) << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1528/A