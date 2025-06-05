#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <int> par, compsize;

int find(int v){
    if(par[v] == v) return v;
    else return par[v] = find(par[v]);
}

void merge(int u, int v){
    int root_u = find(u);
    int root_v = find(v);
    if(root_u != root_v) {
        par[root_u] = root_v;
        compsize[root_v] += compsize[root_u];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    par.assign(n+1, 0);
    compsize.assign(n+1, 1);
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        int last = -1;
        for(int j = 0; j < k; j++){
            int v; cin >> v;
            if(last != -1) merge(last, v);
            last = v;
        }
    }
    for(int i = 1; i <= n; i++) cout << compsize[find(i)] << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1167/C