#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 107;

vector <int> G[N];
ll dp[N][N], val[N][N];
int n, k;

ll dfs(int u, int par, int left){
    if(left == 0) return 0;
    if(dp[u][left] != -1) return dp[u][left]; 

    vector<ll> temp(left + 1, -1);
    temp[0] = 0;

    for(auto v: G[u]){
        if(v == par) continue;
        vector<ll> new_temp(left + 1, -1);
        for(int cur = 0; cur <= left; cur++){
            if(temp[cur] == -1) continue;
            for(int taken = 1; taken <= left - cur; taken++){
                ll child_val = dfs(v, u, taken - 1);
                if(child_val == -1) continue;
                new_temp[cur + taken] = max(new_temp[cur + taken], temp[cur] + val[u][v] + child_val);
            }
        }
        for(int i = 0; i <= left; ++i) temp[i] = max(temp[i], new_temp[i]);
    }

    ll res = 0;
    for(int i = 1; i <= left; ++i) res = max(res, temp[i]);
    return dp[u][left] = res;
}

void solve()
{
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    memset(val, 0, sizeof(val));
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(v);
        G[v].push_back(u);
        val[u][v] = val[v][u] = w;
    }
    cout << dfs(1, -1, k) << "\n";
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
// https://acm.timus.ru/problem.aspx?space=1&num=1018