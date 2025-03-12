#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <ll> x(n), h(n), dp(n), last(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> h[i];
    dp[0] = 1; last[0] = x[0]; // left
    for(int i = 1; i < n - 1; i++){
        if(x[i] - h[i] > last[i-1]){
            dp[i] = dp[i-1] + 1;
            last[i] = x[i]; // left
        }
        else if(x[i] + h[i] < x[i+1]){
            dp[i] = dp[i-1] + 1;
            last[i] = x[i] + h[i]; // right
        }
        else{
            dp[i] = dp[i-1];
            last[i] = x[i]; // standing
        }
    }
    if(n > 1) dp[n-1] = dp[n-2] + 1; // right
    cout << dp[n-1] << "\n";
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
// https://codeforces.com/contest/545/problem/C