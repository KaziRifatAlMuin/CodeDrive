#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

void solve()
{
    ll n, k, q;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <vector<int>> next(n+1, vector<int>(26, n+1));
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < k; j++){
            next[i][j] = next[i+1][j];
        }
        next[i][s[i] - 'a'] = i + 1;
    }
    vector <int> dp(n+2, inf);
    dp[n+1] = 0;
    for(int i = n; i > 0; i--){
        for(int j = 0; j < k; j++){
            dp[i] = min(dp[i], dp[next[i][j]] + 1);
        }
    }
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        int p = 0;
        for(auto c : t){
            p = next[p][c - 'a'];
            if(p > n) break;
        }
        cout << dp[p] << "\n";
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
// https://codeforces.com/contest/2104/problem/E