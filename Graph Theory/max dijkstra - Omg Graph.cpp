#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
const ll inf = 1e18 + 7;

vector <pair<ll,ll>> G[N];
ll dist[2][N];

struct info{
    ll v, w;
    bool const operator < (const info node) const{
        return w > node.w;
    }
};

void dijkstra(int start){
    int flag = (start == 1);
    dist[flag][start] = 0;
    priority_queue <info> q;
    q.push({start, 0});
    while(!q.empty()){
        info cur = q.top();
        q.pop();
        if(cur.w > dist[flag][cur.v]) continue;
        for(auto x : G[cur.v]){
            ll v = x.first;
            ll w = x.second;
            if(dist[flag][v] > max(cur.w, w)){
                dist[flag][v] = max(cur.w, w);
                q.push({v, dist[flag][v]});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) dist[0][i] = dist[1][i] = inf;
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dijkstra(1);
    dijkstra(n);
    ll ans = inf;
    for(int u = 1; u <= n; u++){
        for(auto [v, w] : G[u]){
            ll maxi = max(dist[0][v], dist[1][u]);
            if(maxi >= w) ans = min(ans, w + maxi);
        }
    }
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
// https://codeforces.com/contest/2117/problem/G