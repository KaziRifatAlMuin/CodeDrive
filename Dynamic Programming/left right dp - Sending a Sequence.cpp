#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector <int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector <bool> dp(n+1, 0);
    dp[0] = true; // dp[i] = is possible [0 ... i] 
    for(int i = 1; i <= n; i++){
        if(i - v[i] - 1 >= 0) dp[i] = dp[i] | dp[i - v[i] - 1]; // contribute left
        if(i + v[i] <= n) dp[i + v[i]] = dp[i + v[i]] | dp[i - 1]; // contribute right
    }
    if(dp[n]) cout << "YES\n";
    else cout << "NO\n";
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