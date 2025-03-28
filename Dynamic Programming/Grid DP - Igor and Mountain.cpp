#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

void solve() {
    int n, m, d1, d0;
    cin >> n >> m >> d1;
    d0 = sqrt(1.0 * d1 * d1  - 1);
    ll dp[n+2][m+2][2];
    char s[n+2][m+2];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
        }
    }
    ll ans = 0;
    memset(dp, 0, sizeof(dp));
    vector <ll> pre0(m+2), pre1(m+2);
    for(int j = 1; j <= m; j++) dp[n][j][0] = (s[n][j] == 'X' ? 1 : 0);
    for(int j = 1; j <= m; j++){
        pre0[j] = pre0[j-1] + dp[n][j][0];
        pre1[j] = pre1[j-1] + dp[n][j][1];
    }
    for(int j = 1; j <= m; j++) {
        if(s[n][j] == '#') continue;
        int L1 = max(1, j - d1), R1 = min(m, j + d1);
        dp[n][j][1] = ((pre0[R1] - pre0[L1-1]) % mod - dp[n][j][0]) % mod;
        dp[n][j][1] = (dp[n][j][1] + mod) % mod;
    }
    pre1.assign(m+2,0);
    for(int j = 1; j <= m; j++) pre1[j] = (pre1[j-1] + dp[n][j][1]) % mod;

    for(int i = n-1; i >= 1; i--){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '#') continue;
            int L0 = max(1, j - d0), R0 = min(m, j + d0);
            dp[i][j][0] += (pre0[R0] - pre0[L0-1]) % mod + (pre1[R0] - pre1[L0-1]) % mod;
            dp[i][j][0] %= mod;
        }
        pre0.assign(m+2,0);
        for(int j = 1; j <= m; j++) pre0[j] = (pre0[j-1] + dp[i][j][0]) % mod;
        for(int j = 1; j <= m; j++) {
            if(s[i][j] == '#') continue;
            int L1 = max(1, j - d1), R1 = min(m, j + d1);
            dp[i][j][1] = (((pre0[R1] - pre0[L1-1]) % mod - dp[i][j][0]) % mod) % mod;
            dp[i][j][1] = (dp[i][j][1] + mod) % mod;
        }
        pre1.assign(m+2,0);
        for(int j = 1; j <= m; j++) pre1[j] = (pre1[j-1] + dp[i][j][1]) % mod;
    }
    for(int j = 1; j <= m; j++) {
        ans = (ans + (dp[1][j][0] + dp[1][j][1]) % mod) % mod;
        ans = (ans + mod) % mod;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/2091/problem/F