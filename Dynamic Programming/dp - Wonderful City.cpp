#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long inf = 1e17;

ll solvedp(vector <vector<ll>> g, vector <ll> cost){
    int n = cost.size();
    vector <bool> ban1(n), ban2(n), ban3(n); // (FF,TT), FT, TF
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i-1][j] == g[i][j]) ban1[i]= true;
            if(g[i-1][j] == g[i][j] + 1) ban2[i]= true;
            if(g[i-1][j] + 1 == g[i][j]) ban3[i]= true;
        }
    }
    vector <ll> dp0(n, inf), dp1(n, inf);
    dp0[0] = 0, dp1[0] = cost[0];
    for(int i = 1; i < n; i++){
        if(ban1[i] && ban2[i] && ban3[i]) return inf;
        else if(ban1[i] && ban2[i]) dp0[i] = dp1[i-1], dp1[i] = inf;
        else if(ban1[i] && ban3[i]) dp0[i] = inf, dp1[i] = dp0[i-1] + cost[i];
        else if(ban2[i] && ban3[i]) dp0[i] = dp0[i-1], dp1[i] = dp1[i-1] + cost[i];
        else if(ban1[i]) dp0[i] = dp1[i-1], dp1[i] = dp0[i-1] + cost[i];
        else if(ban2[i]) dp0[i] = min(dp1[i-1], dp0[i-1]), dp1[i] = dp1[i-1] + cost[i];
        else if(ban3[i]) dp0[i] = dp0[i-1], dp1[i] = min(dp1[i-1], dp0[i-1]) + cost[i];
        else dp0[i] = min(dp0[i-1], dp1[i-1]), dp1[i] = min(dp0[i-1], dp1[i-1]) + cost[i];
    }
    return min(dp0[n-1], dp1[n-1]);
}

void solve(){
    ll n;
    cin >> n;
    vector<vector<ll>> g(n, vector<ll>(n));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    vector<ll> row(n), col(n);
    for(ll i = 0; i < n; i++) cin >> row[i];
    for(ll i = 0; i < n; i++) cin >> col[i];
    ll ans1 = solvedp(g, row);
    vector<vector<ll>> transposed(n, vector<ll>(n));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            transposed[i][j] = g[j][i];
        }
    }
    ll ans2 = solvedp(transposed, col);
    if(ans1 + ans2 >= inf) cout << -1 << "\n";
    else cout << ans1 + ans2 << "\n";
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
// https://codeforces.com/contest/2096/problem/C