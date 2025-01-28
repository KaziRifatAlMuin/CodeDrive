#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e6 + 7;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector <ll> v(N), pre1(N+1), pre2(N+1);
    while(n--){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        v[l]++, v[r+1]--;
    }
    for(int i = 0; i < N; i++){
        pre1[i+1] = pre1[i] + v[i];
    }

    // for(int i = 0; i < 12; i++){
    //     cout << pre1[i] << " ";
    // }
    // cout << "\n";

    for(int i = 0; i < N; i++){
        pre2[i+1] = pre2[i] + (pre1[i] >= k);
    }

    // for(int i = 0; i < 12; i++){
    //     cout << pre2[i] << " ";
    // }
    // cout << "\n";

    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << pre2[r+1] - pre2[l] << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://maang.in/problems/Good-Numbers-23