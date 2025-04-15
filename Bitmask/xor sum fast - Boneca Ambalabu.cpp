#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) (((x) >> (k)) & 1)
#define to_Binary(n) bitset<sizeof(n) * 1>(n).to_string()

void solve()
{
    ll n;
    cin >> n;
    vector <ll> v(n), cnt(31);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        for(int k = 0; k <= 30; k++) cnt[k] += CheckBit(v[i], k);
    }
    ll ans = 0, sum;
    for(auto k : v){
        sum = 0; // sum = c0 * 2^0 + c1 * 2^1 + ... + c30 * 2^30
        for(int j = 0; j <= 30; j++){
            ll c = !CheckBit(k, j) ? cnt[j] : (n - cnt[j]);
            sum += c * (1 << j);
            // cout << sum << " ";
        }
        ans = max(ans, sum);
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
// https://codeforces.com/contest/2094/problem/E