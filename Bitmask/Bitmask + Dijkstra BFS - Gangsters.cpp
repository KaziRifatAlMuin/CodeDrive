#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
#define SetBit(x, k) ((x) |= (1ll << (k)))
#define ClearBit(x, k) ((x) &= ~(1ll << (k)))
#define CheckBit(x, k) (((x) >> (k)) & 1ll)

vector <vector<ll>> G;
vector <ll> dist;
vector <ll> daku, c, cost, mask;

struct info{
    ll v, w;
    bool const operator < (const info node) const{
        return w > node.w;
    }
};

ll n, m, p, k;

void bfs(ll start, ll bit){
    queue <ll> q;
    q.push(start);
    SetBit(mask[start], bit);
    vector <bool> vis(n+1, false);
    vector <ll> level(n+1, 0);
    vis[start] = true;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto v : G[u]){
            if(!vis[v]){
                q.push(v);
                level[v] = level[u] + 1;
                vis[v] = true;
                if(level[v] <= k){
                    SetBit(mask[v], bit);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m >> p >> k;
    vector <ll> daku(p), c(p), cost(1 << p);
    daku.assign(p, 0);
    c.assign(p, 0);
    cost.assign((1 << p), 0);
    mask.assign(n+1, 0);
    G.assign(n+1, {});
    vector <pair<ll,ll>> edge;
    for(ll i = 0; i < p; i++) {
        cin >> daku[i];
        SetBit(mask[daku[i]], i);
    }
    for(ll i = 0; i < p; i++) cin >> c[i];

    for(ll i = 0; i < (1 << p); i++){
        for(ll j = 0; j < p; j++){
            if((i >> j) & 1) cost[i] += c[j];
        }
    }
    // for(ll i = 0; i < (1 << p); i++) cout << cost[i] << " ";

    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(ll i = 0; i < p; i++){
        bfs(daku[i], i);
    }

    ll st, en;
    cin >> st >> en;
    // cout << st << " " << en << ": ";

    dist.assign(n+1, 1e17);
    dist[st] = cost[mask[st]];
    priority_queue <info> q;
    q.push({st, cost[mask[st]]});
    while(!q.empty()){
        info cur = q.top();
        q.pop();
        if(cur.w > dist[cur.v]) continue;
        for(auto v : G[cur.v]){
            ll w = cost[mask[cur.v] | mask[v]];
            if(dist[v] > w){
                dist[v] = w;
                mask[v] = mask[cur.v] | mask[v];
                q.push({v, dist[v]});
            }
        }
    }
    cout << dist[en] << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/gym/101059/problem/C