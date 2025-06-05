#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> G;
vector <int> c, ans;

void dfs(int u, int par = -1){
    int zerochild = 0;
    for(auto v : G[u]){
        if(v == par) continue;
        if(c[v] == 0) zerochild++;
        dfs(v, u);
    }
    if(c[u] == 1 && zerochild == 0) ans.push_back(u);
}

void solve(){
    int n;
    cin >> n;
    G.assign(n+1, {});
    c.assign(n+1, 0);
    ans.clear();
    int root = -1;
    for(int u = 1; u <= n; u++){
        int v;
        cin >> v >> c[u];
        if(v == -1) root = u;
        else{
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    dfs(root);
    if(ans.size() == 0) cout << -1 << "\n";
    else{
        sort(ans.begin(), ans.end());
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1143/C