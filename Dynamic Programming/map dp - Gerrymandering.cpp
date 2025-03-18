#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <pair<int,int>, int> dp;
int n;
string s[2];

int check(pair<int,int> A, pair<int,int> B, pair<int,int> C){
    int cnt = 0;
    cnt += (s[A.first][A.second] == 'A');
    cnt += (s[B.first][B.second] == 'A');
    cnt += (s[C.first][C.second] == 'A');
    return cnt >= 2;
}

int run(int i, int j){
    if(i == n || j == n) return 0;
    if(dp.count({i,j})) return dp[{i,j}];
    int opt1 = 0, opt2 = 0, opt3 = 0;
    if(max(i+2, j+2) < n) opt1 = check({0,i},{0,i+1},{0,i+2}) + check({1,j},{1,j+1},{1,j+2}) + run(i+3,j+3);
    if((j + 1 < n && i == j) || i == j + 1) opt2 = check({0,i},{1,j},{1,j+1}) + run(i+1,j+2);
    if((i + 1 < n && i == j) || j == i + 1) opt3 = check({0,i},{1,j},{0,i+1}) + run(i+2,j+1);
    return dp[{i,j}] = max({opt1, opt2, opt3});
}

void solve() {
    cin >> n >> s[0] >> s[1];
    dp.clear();
    cout << run(0,0) << "\n";
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
// https://codeforces.com/contest/2022/problem/C