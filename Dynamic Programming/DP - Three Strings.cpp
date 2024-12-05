#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            int pos = i + j;
            if(pos >= m + n) continue;
            if(i < n){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (a[i] != c[pos]));
            }
            if(j < m){
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + (b[j] != c[pos]));
            }
        }
    }
    cout << dp[n][m] << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2050/problem/E