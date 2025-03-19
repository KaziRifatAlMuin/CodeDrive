#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
const long long inf = 1e18;

vector<pair<ll,ll>> G[N];
vector<bool> hasHorse;

struct info{
    ll v, w;
    bool horse;
    bool operator < (const info &node) const{
        return w > node.w;
    }
};

vector<ll> dijkstra(int start, int n){
    vector<ll> dist(n+1,inf);
    vector<vector<ll>> d(n+1,vector<ll>(2,inf)); // 2D vector for state handling
    d[start][0] = 0;
    priority_queue<info> q;
    q.push({start,0,0});
    while(!q.empty()){
        info cur = q.top();
        q.pop();
        bool horse = cur.horse || hasHorse[cur.v];
        if(cur.w > d[cur.v][horse]) continue;
        for(auto [v,w] : G[cur.v]){
            ll cost = horse ? w/2 : w;
            if(d[v][horse] > cur.w + cost){
                d[v][horse] = cur.w + cost; // update according to state
                q.push({v,d[v][horse],horse}); // push in queue also maintaining state
            }
        }
    }
    for(int i = 0; i <= n; i++) dist[i] = min(d[i][0],d[i][1]);
    return dist;
}

void solve(){
    int n,m,h;
    cin >> n >> m >> h;
    for(int i = 0; i <= n; i++) G[i].clear();
    hasHorse.assign(n+1,0);
    for(int i = 0; i < h; i++){
        int c; cin >> c;
        hasHorse[c] = true;
    }
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    vector<ll> dist1 = dijkstra(1,n), dist2 = dijkstra(n,n);
    ll ans = inf;
    for(int i = 1; i <= n; i++){
        ans = min(ans,max(dist1[i],dist2[i]));
    }
    if(ans==inf) cout << -1 << "\n";
    else cout << ans << "\n";
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
// https://codeforces.com/problemset/problem/2014/E