#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];
    if(n == 1 && m == 1){
        cout << "0\n";
        return;
    }
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 && s[i][j] == 'U') || (i == n - 1 && s[i][j] == 'D') ||
                (j == 0 && s[i][j] == 'L') || (j == m - 1 && s[i][j] == 'R')) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    // multisource bfs
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
 
        if(i - 1 >= 0 && !vis[i - 1][j] && s[i - 1][j] == 'D') {
            vis[i - 1][j] = 1;
            q.push({i - 1, j});
        }
        if(j - 1 >= 0 && !vis[i][j - 1] && s[i][j - 1] == 'R') {
            vis[i][j - 1] = 1;
            q.push({i, j - 1});
        }
        if(i + 1 < n && !vis[i + 1][j] && s[i + 1][j] == 'U') {
            vis[i + 1][j] = 1;
            q.push({i + 1, j});
        }
        if(j + 1 < m && !vis[i][j + 1] && s[i][j + 1] == 'L') {
            vis[i][j + 1] = 1;
            q.push({i, j + 1});
        }
 
        auto check = [&](int ii, int jj) {
            if(ii < 0 || ii >= n || jj < 0 || jj >= m) return;
            if(vis[ii][jj] || s[ii][jj] != '?') return;
            if(ii - 1 >= 0 && !vis[ii - 1][jj]) return;
            if(jj - 1 >= 0 && !vis[ii][jj - 1]) return;
            if(ii + 1 < n && !vis[ii + 1][jj]) return;
            if(jj + 1 < m && !vis[ii][jj + 1]) return;
            vis[ii][jj] = 1;
            q.push({ii, jj});
        };
 
        check(i - 1, j);
        check(i + 1, j);
        check(i, j - 1);
        check(i, j + 1);
    }
 
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == 0) ans++;
        }
    }
    cout << ans << '\n';
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
// https://codeforces.com/problemset/problem/2034/C