#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> G;
vector <int> cnt; // happiness if i-th is industry

int dfs(int u, int par = -1){
    int child = 0;
    for(auto v : G[u]){
        if(v == par) continue;
        cnt[v] = cnt[u] + 1;
        child += (1 + dfs(v, u));
    }
    cnt[u] -= child;
    return child;
}

void solve(){
    int n, k;
    cin >> n >> k;
    G.assign(n+1, {});
    cnt.assign(n+1, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    cnt[0] = -1e9;
    ll ans = 0;
    sort(cnt.rbegin(), cnt.rend());
    for(int i = 0; i < k; i++) ans += cnt[i];
    cout << ans << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1336/A