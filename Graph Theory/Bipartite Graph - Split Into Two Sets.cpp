#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <int> G[N];
vector <bool> visited;

int dfs(int u){
    visited[u] = true;
    for(auto v : G[u]){
        if(!visited[v]){
            return dfs(v) + 1; // add 1 to the path length
        }
    }
    return 1; // for leaf node
}

void solve()
{
    int n;
    cin >> n;
    vector <int> cnt(n+1);
    for(int i = 0; i <= n; i++) G[i].clear();
    visited.assign(n+1, false);
    bool ok = true;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        if(x == y || G[x].size() > 2 || G[y].size() > 2) ok = false;
    }
    if(!ok) cout << "NO\n";
    else{
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                if(dfs(i) & 1){ // odd-sized component
                    cout << "NO\n"; // can't be 2-edge-colored or bipartite
                    return;
                }
            }
        }
        cout << "YES\n";
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
// https://codeforces.com/problemset/problem/1702/E