#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005, mod = 1e9 + 7;

ll dp[N][N][2];
ll n, k;

ll run(ll pos, ll k, ll isright = 1){
    if(pos < 1 || pos > n || k == 1) return 0;
    if(dp[pos][k][isright] != -1) return dp[pos][k][isright];
    ll left = 0, right = 0;
    if(isright){
        left = 1 + run(pos - 1, k - 1, 0); // create a particle in opposite
        right = run(pos + 1, k, 1); // same direction creating none, contributes later
    }
    else{
        left = run(pos - 1, k, 0); // same direction creating none, contributes later
        right = 1 + run(pos + 1, k - 1, 1); // create a particle in opposite
    }
    return dp[pos][k][isright] = ((left % mod) + (right % mod)) % mod;
}

void solve(){
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << 1 + run(1, k) << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1498/C