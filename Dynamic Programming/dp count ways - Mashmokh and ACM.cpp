#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005, mod = 1e9 + 7;

ll dp[N][N];
ll n, k;

ll run(ll last, ll rem){
    if(rem <= 0) return 1;
    if(dp[last][rem] != -1) return dp[last][rem];
    ll ans = 0;
    for(ll i = last; i <= n; i += last) ans = (ans + run(i, rem - 1)) % mod;
    return dp[last][rem] = ans;
}

void solve(){
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << run(1, k) << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/414/B