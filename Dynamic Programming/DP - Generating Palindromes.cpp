#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 102;

int dp[N][N];
string s;

int run(int first, int last) {
    if(first > last) return 0;
    if(dp[first][last] != -1) return dp[first][last];
    int ans = INT_MAX;
    if(s[first] == s[last]) ans = min(ans, run(first + 1, last - 1));
    else ans = min(ans, 1 + min(run(first + 1, last), run(first, last - 1)));
    return dp[first][last] = ans;
}

void solve() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << run(0, s.size() - 1) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, cs = 1, st = clock();
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://lightoj.com/problem/generating-palindromes