#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

vector <int> G[N];
int iscat[N], ans = 0, m;

void dfs(int u, int par, int cat){
    if(iscat[u]) cat++;
    else cat = 0;
    if(cat > m) return; // Stop if consecutive cats exceed m
    int ok = 1; // Assume u is a leaf node
    for(auto v : G[u]){
        if(v != par){   // Avoid going back to the parent node
            ok = 0;     // u is not a leaf if it has a child
            dfs(v, u, cat);
        }
    }
    if(ok) ans++; // If u is a leaf node, increase the count
}

void solve(){
    int n;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> iscat[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1, 0);
    cout << ans << "\n";
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
// https://codeforces.com/contest/580/problem/C