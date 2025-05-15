#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    s = '#' + s;
    string ss[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector <vector<int>> dp(6, vector <int>(n+1, 0));
    for(int j = 0; j < 6; j++){
        for(int i = 1; i <= n; i++){
            dp[j][i] = dp[j][i-1] + (ss[j][i % 3] != s[i]);
        }
    }
    while(m--){
        int l, r;
        cin >> l >> r;
        int ans = n + 1;
        for(int j = 0; j < 6; j++){
            ans = min(ans, dp[j][r] - dp[j][l-1]);
        }
        cout << ans << "\n";
    }
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
// https://codeforces.com/problemset/problem/1555/D