#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 6007;

vector <int> G[N];
ll dp[N][2], val[N];

void dfs(int u, int par = -1){
    if(u == par) return;
    dp[u][1] = val[u];
    dp[u][0] = 0;
    for(auto v: G[u]){
        if(v == par) continue;
        dfs(v, u);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}

void solve()
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(val, 0, sizeof(val));
    for(int i = 1; i <= n; i++) cin >> val[i];
    
    while(1){
        int u, v;
        cin >> u >> v;
        if(u == 0 && v == 0) break;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://acm.timus.ru/problem.aspx?space=1&num=1039