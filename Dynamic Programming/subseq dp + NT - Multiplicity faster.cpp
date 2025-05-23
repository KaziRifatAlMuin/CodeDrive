#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7, mod = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector <int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector <int> dp(n+1);
    dp[0] = 1; // empty subsequence, which starts every good subseq
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        vector <int> divs;
        for(int j = 1; j * j <= v[i]; j++){
            if(v[i] % j == 0 && j <= n){
                divs.push_back(j);
                if(v[i] / j != j && v[i] / j <= n){
                    divs.push_back(v[i] / j);
                }
            }
        }
        sort(divs.rbegin(), divs.rend());
        for(auto j : divs){
            dp[j] = (dp[j] + dp[j-1]) % mod;
            // We are assuming that dp[j-1] refers to the previous dp row
            // To maintain it, this loop must run greater to smaller
        }
    }
    for(int j = 1; j <= n; j++) ans = (ans + dp[j]) % mod;
    cout << ans << "\n";
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
// https://codeforces.com/problemset/problem/1061/C