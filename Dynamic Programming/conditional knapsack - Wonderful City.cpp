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
    vector <vector <ll>> dp(n, vector <ll>(2, inf));
    dp[0][0] = 0, dp[0][1] = cost[0];
    for(int i = 1; i < n; i++){
        for(int prev = 0; prev <= 1; prev++){
            for(int cur = 0; cur <= 1; cur++){
                bool skip = false;
                if(prev == 0 && cur == 0 && ban1[i]) skip = true;
                if(prev == 0 && cur == 1 && ban2[i]) skip = true;
                if(prev == 1 && cur == 0 && ban3[i]) skip = true;
                if(prev == 1 && cur == 1 && ban1[i]) skip = true;
                if(skip) continue;
                ll cand = dp[i-1][prev] + (cur ? cost[i] : 0);
                dp[i][cur] = min(dp[i][cur], cand);
            }
        }
    }
    return min(dp[n-1][0], dp[n-1][1]);
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
    if(ans1 == inf || ans2 == inf) cout << -1 << "\n";
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