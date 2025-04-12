#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

vector <int> G[N];
vector <ll> tin, tout, depth, maxdepth;
int t;

// Finds max depth of subtree of u too
void dfs(int u, int par = 0){
    maxdepth[u] = depth[u];
    for(auto v : G[u]){
        if(v != par){
            depth[v] = depth[u] + 1;
            dfs(v, u);
            maxdepth[u] = max(maxdepth[u], maxdepth[v]); 
        }
    }
}


void solve(){
    int n;
    cin >> n;
    depth.assign(n+1,0);
    maxdepth.assign(n+1,0);
    for(int i = 0; i <= n; i++) G[i].clear();
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    vector <int> diff(n+2), pre(n+3); // Difference array & prefix array

    for(int i = 1; i <= n; i++){
        diff[depth[i]]++, diff[maxdepth[i]+1]--; // Delta Encoding
    }
    int stay = 0;
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + diff[i-1];
        stay = max(pre[i], stay);
    }
    cout << n - stay << "\n";
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
// https://codeforces.com/problemset/problem/2018/C