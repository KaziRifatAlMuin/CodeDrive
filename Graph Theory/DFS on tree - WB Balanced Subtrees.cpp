#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> G;
string s;
ll ans = 0;

// for each child v of node u:
//     dfs(v) → get subtree info
//     accumulate child info into current node (u)
// Now process current node itself (after children)
// return result for tree rooted at u

pair<int, int> dfs(int u, int par = -1) {
    int black = 0, white = 0;
    for(auto v : G[u]) {
        if(v == par) continue;
        // compute black and white in subtree at root v
        auto [b, w] = dfs(v, u); // after dfs, all children of v explored
        black += b; // add black from child
        white += w; // add white from child
    }
    // All children of u explored here, now process current
    // Include the current node's color in the count
    if(s[u] == 'B') black++;
    else white++;

    if(black == white) ans++; // Update what I need
    return {black, white}; // Return this node including children info
}

void solve(){
    int n; cin >> n;
    G.assign(n+1, {});
    for(int u = 2; u <= n; u++){
        int v; cin >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> s;
    s = "#" + s;
    ans = 0; dfs(1);
    cout << ans << "\n";
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
// https://codeforces.com/problemset/problem/1676/G\