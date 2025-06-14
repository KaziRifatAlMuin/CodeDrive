#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18 + 7;

vector <vector<int>> G;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    G.assign(n+1, {});
    vector <ll> a(l);
    ll sum = 0, evensum = 0, oddsum = 0, minodd = inf;
    for(int i = 0; i < l; i++){
        cin >> a[i]; sum += a[i];
        if(a[i] & 1) minodd = min(minodd, a[i]);
    }
    if(sum & 1){
        oddsum = sum;
        if(minodd != inf) evensum = sum - minodd;
    }
    else{
        evensum = sum;
        if(minodd != inf) oddsum = sum - minodd;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // 2D BFS for even-odd length path
    vector <vector<ll>> dist(n+1, vector<ll> (2, inf));
    queue <pair<ll,ll>> q;
    q.push({1, 0}); dist[1][0] = 0;
    while(!q.empty()){
        auto [cur, parity] = q.front(); q.pop();
        for(auto v : G[cur]){
            ll new_parity = parity ^ 1;
            if(dist[v][new_parity] != inf) continue;
            dist[v][new_parity] = dist[cur][parity] + 1;
            q.push({v, new_parity});
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(dist[i][1] <= oddsum || dist[i][0] <= evensum) cout << '1';
        else cout << '0';
    }
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
// https://codeforces.com/contest/2109/problem/D