#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

void solve(){
    int n;
    vector <vector<ll>> v, dp;
    cin >> n;
    v.assign(n+1, vector<ll> (2, 0));
    dp.assign(n+1, vector<ll> (2, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= n; j++){
            cin >> v[j][i];
        }
    }
    // dp[i][0] = best using columns 1..i, taking player (i,0) last
    // dp[i][1] = same but taking player (i,1) last
    dp[1][0] = v[1][0];
    dp[1][1] = v[1][1];
    for(int i = 2; i <= n; i++){
        // If I take (i,0), I must have come from either (i-1,1) or (i-2,1)
        dp[i][0] = v[i][0] + max(dp[i-1][1], dp[i-2][1]);
        // If I take (i,1), I must have come from either (i-1,0) or (i-2,0)
        dp[i][1] = v[i][1] + max(dp[i-1][0], dp[i-2][0]);
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1195/C