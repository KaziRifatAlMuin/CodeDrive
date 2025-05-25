#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<pair<ll,ll>>> G;
vector <ll> b;
vector <ll> dp;

void solve(){
    ll n, m;
    cin >> n >> m;
    b.assign(n+1, 0);
    G.assign(n+1, {});
    dp.assign(n+1, -1e18);
    for(ll i = 1; i <= n; i++) cin >> b[i];
    for(ll i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        G[v].push_back({u, w}); // store in-vertices instead out
    }
    ll low = 1, high = 1e18, ans = -1;
    while(low <= high){ // FFFFFTTTTT
        ll mid = low + (high - low) / 2;
        dp.assign(n+1, -1e18);
        dp[1] = min(b[1], mid); // must limit in base case too
        for(ll v = 2; v <= n; v++){
            for(auto [u, w] : G[v]){
                if(dp[u] >= w){
                    dp[v] = max(dp[v], min(mid, dp[u] + b[v])); // capping battery
                }
            }
        }
        if(dp[n] == -1e18) low = mid + 1;
        else high = mid - 1, ans = dp[n];
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
// https://codeforces.com/contest/2110/problem/D