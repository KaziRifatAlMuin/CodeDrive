#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[60][60][60];

void pre(){
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            for(int k = 0; k < 60; k++){
                if(i == 0 && j == 0) dp[i][j][k] = 0; // base case
                else dp[i][j][k] = 1e18; // initialization
            }
        }
    }
    for(int a = 0; a < 60; a++){
        for(int b = 0; b < 60; b++){
            for(int k = 1; k < 60; k++){
                ll opt1 = 1e18, opt2 = 1e18;
                if(a - k >= 0) opt1 = (1ll << k) + dp[a-k][b][k-1]; // take
                if(b - k >= 0) opt2 = (1ll << k) + dp[a][b-k][k-1]; // take
                dp[a][b][k] = min({opt1, opt2, dp[a][b][k-1]}); // not take
            }
        }
    }
}

void solve() {
    ll x, y;
    cin >> x >> y;
    ll ans = 1e18;
    for(int a = 0; a < 60; a++){
        for(int b = 0; b < 60; b++){
            if((x >> a) == (y >> b)) ans = min(ans, dp[a][b][59]);
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2075/problem/D