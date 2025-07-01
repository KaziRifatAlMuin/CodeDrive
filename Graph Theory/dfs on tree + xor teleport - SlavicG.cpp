#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector <vector<pair<int,int>>> G;
vector <int> pre, pre2;
set <int> st;
int n, a, b;

void dfs(int u, int par = -1){
    if(u == b) return; // stop at b
    st.insert(pre[u]);
    for(auto [v, w] : G[u]){
        if(v == par) continue;
        pre[v] = pre[u] ^ w;
        dfs(v, u);
    }
}

void dfs2(int u, int par = -1){
    for(auto [v, w] : G[u]){
        if(v == par) continue;
        pre2[v] = pre2[u] ^ w;
        dfs2(v, u);
    }
}

void solve(){
    cin >> n >> a >> b;
    st.clear();
    G.assign(n+1, {});
    pre.assign(n+1, 0);
    pre2.assign(n+1, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs(a);
    dfs2(b);
    bool ok = false;
    if(pre[b] == 0) ok = true;
    for(int i = 1; i <= n; i++){
        if(i == b) continue;
        if(st.count(pre2[i]) > 0) ok = true;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
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
// https://codeforces.com/contest/1760/problem/G