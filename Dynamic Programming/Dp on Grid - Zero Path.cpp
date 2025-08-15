#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> v;
vector <vector<int>> dp;

int n, m;

int run(int row, int col, int k){
    if(row >= n || col >= m) return 0;
    if(dp[row][col] != -1) return dp[row][col];
    return dp[row][col] = (v[row][col] == k) + max(run(row+1, col, k), run(row, col+1, k));
}

void solve() {
    cin >> n >> m;
    v.assign(n, vector <int> (m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    dp.assign(n, vector <int> (m, -1));
    int one = run(0, 0, 1);
    dp.assign(n, vector <int> (m, -1));
    int minusone = run(0, 0, -1);
    int need = m+n-1;
    if(need % 2 == 0 && one >= (need/2) && minusone >= (need/2)) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1695/C