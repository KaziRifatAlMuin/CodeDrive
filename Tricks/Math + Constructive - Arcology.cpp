#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll mex = max(n / (m+1), k);
    for(int i = 0; i < n; i += mex){
        for(int j = 0; j < mex && i+j < n; j++){
            cout << j << " ";
        }
    }
    cout << "\n";
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
// https://codeforces.com/contest/2084/problem/D