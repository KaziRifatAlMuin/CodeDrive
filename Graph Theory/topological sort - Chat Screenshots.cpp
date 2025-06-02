#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n+1);
    vector<int> indeg(n+1);
    for(int j = 0; j < k; j++){
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 2; i < n; i++) {
            G[v[i-1]].push_back(v[i]); // v[i-1] -> v[i]
            indeg[v[i]]++;
        }
    }

    // Topological sort (to get all n vertices in ord, must have no cycle)
    
    queue<int> q;
    for(int i = 1; i <= n; i++) if(indeg[i] == 0) q.push(i);
    vector <int> ord;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ord.push_back(u);
        for(int v : G[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }
    // It can be done by checking if it is cycle too
    
    if(ord.size() == n) cout << "YES\n";
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
// https://codeforces.com/problemset/problem/1931/F