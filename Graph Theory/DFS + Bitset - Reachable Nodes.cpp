#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 7;

bool visited[N];
bitset <N> b[N];
vector <int> G[N];

void dfs(int u){
    b[u].set(u);
    visited[u] = true;
    for(auto v : G[u]){
        if(!visited[v]) dfs(v);
        b[u] |= b[v];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i);
    }
    for(int i = 1; i <= n; i++){
        cout << b[i].count() << " ";
    }
    cout << "\n";
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