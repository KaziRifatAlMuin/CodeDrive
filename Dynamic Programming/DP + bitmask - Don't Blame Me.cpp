#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7, mod = 1e9 + 7;

ll dp[N][64][2];

vector <int> v;
int n, k;

ll run(int i, int AND, int isEmpty){
    if(i >= n){
        if(isEmpty) return 0;
        if(__builtin_popcount(AND) == k) return 1;
        return 0;
    }
    if(dp[i][AND][isEmpty] != -1) return dp[i][AND][isEmpty];
    ll take = 0;
    if(isEmpty) take = run(i+1, v[i], 0);
    else take = run(i+1, AND & v[i], 0);
    ll notTake = run(i+1, AND, isEmpty);
    ll res = (take + notTake) % mod;
    return dp[i][AND][isEmpty] = res;
}

void solve(){
    cin >> n >> k;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    // memset(dp, -1, sizeof(dp)); this gives TLE
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 64; j++){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    cout << run(0, 0, 1) << "\n";
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

// https://codeforces.com/contest/1829/problem/H