#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <int> par;
vector <int> G1[N], G2[N];
vector <int> vis1, vis2;

void dfs1(int u){
    vis1[u] = true;
    for(auto v : G1[u]){
        if(!vis1[v]){
            dfs1(v);
        }
    }
}

void dfs2(int u){
    vis2[u] = true;
    for(auto v : G2[u]){
        if(!vis2[v]){
            dfs2(v);
        }
    }
}

int find(int v){
    if(par[v] == v) return v;
    else return par[v] = find(par[v]);
}

void merge(int u, int v){
    int root_u = find(u);
    int root_v = find(v);
    if(root_u != root_v) par[root_u] = root_v;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    par.assign(n+1, 0);
    vis1.assign(n+1, false);
    vis2.assign(n+1, false);
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 0; i <= n; i++) G1[i].clear(), G2[i].clear();
    vector <pair<int,int>> edges;
    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    
    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
        merge(u, v);
    }

    ll ans = 0;

    for(auto [u, v] : edges){
        if(find(u) == find(v)){
            G1[u].push_back(v);
            G1[v].push_back(u);
        }
        else ans++;
    }

    // cout << ans << "\n";

    int size1 = 0, size2 = 0;
    for(int i = 1; i <= n; i++){
        if(!vis1[i]){
            dfs1(i);
            size1++;
        }
        if(!vis2[i]){
            dfs2(i);
            size2++;
        }
    }
    cout << ans + size1 - size2 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2060/problem/E