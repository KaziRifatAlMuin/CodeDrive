#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int dp[N][2][6];
int n, k, z;
vector <int> v;

ll run(int pos, int prevleft, int left){
    int move = pos + 2 * left;
    if(move >= k) return v[pos];
    if(dp[pos][prevleft][left] != -1) return dp[pos][prevleft][left];
    ll opt = v[pos] + run(pos + 1, 0, left);
    if(!prevleft && left + 1 <= z && pos - 1 >= 0) opt = max(opt, v[pos] + run(pos-1, 1, left+1));
    return dp[pos][prevleft][left] = opt;
}

void solve(){
    cin >> n >> k >> z;
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << run(0, 0, 0) << "\n";
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
// https://codeforces.com/problemset/problem/1389/B