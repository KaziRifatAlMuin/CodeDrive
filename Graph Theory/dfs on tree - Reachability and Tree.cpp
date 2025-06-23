#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> G;
vector <int> dist;
vector <pair<int,int>> ans;

void dfs(int u, int par, int k){
    if(k) ans.push_back({u, par});
    else ans.push_back({par, u});
    for(auto v : G[u]){
        if(v == par) continue;
        dfs(v, u, k ^ 1);
    }
}

void solve(){
    int n;
    cin >> n;
    G.assign(n+1, {});
    dist.assign(n+1, 0);
    ans.clear();
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int su = -1;
    for(int u = 1; u <= n; u++){
        if(G[u].size() == 2) su = u;
    }
    if(su == -1){
        cout << "NO\n";
        return;
    }
    dfs(G[su][0], su, 0);
    dfs(G[su][1], su, 1);
    cout << "YES\n";
    bool done = false;
    for(auto [u, v] : ans){
        cout << u << " " << v << "\n";
    }
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