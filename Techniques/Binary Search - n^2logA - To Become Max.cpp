#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> v(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> v[i], ans = max(ans, v[i]);
    ll low = ans, high = ans + k;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        bool ok = false;
        ll x = mid;
        for(int i = 0; i < n; i++){
            ll op = 0;
            vector <ll> b(n);
            b[i] = x;
            for(int j = i; j < n; j++){
                if(b[j] <= v[j]) break;
                if(j + 1 >= n){
                    op = k + 1;
                    break;
                }
                op += (b[j] - v[j]);
                b[j+1] = max(0ll, b[j] - 1);
            }
            if(op <= k) ok = true;
        }
        // TTTTTTFFFFF
        if(ok) low = mid + 1, ans = mid;
        else high = mid - 1;
    }
    cout << ans << "\n";
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
// https://codeforces.com/problemset/problem/1856/C