#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e5 + 7;

vector <int> tree[N];

void dfs(int u, int par = -1){
    for(auto v : tree[u]){
        if(v != par){
            dfs(v, u);
        }
    }
    cout << u << " "; // Post Order Traversal
}

void solve() {
    int n, st, en;
    cin >> n >> st >> en;
    for(int i = 0; i <= n; i++) tree[i].clear();
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(en);
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
// https://codeforces.com/contest/2071/problem/C