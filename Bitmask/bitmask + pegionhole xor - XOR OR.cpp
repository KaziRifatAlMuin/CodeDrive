#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
typedef long long ll;


void solve()
{
    int n; cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    if(n > 21) cout << 0 << "\n"; // pigeonhole principle
    else{
        ll lim = 1 << n;
        ll ans = 1e18;
        for(int mask = 1; mask < lim - 1; mask++){
            ll xorr = 0, orr = 0;
            for(int j = 0; j < n; j++){
                if((mask >> j) & 1) xorr ^= v[j];
                else orr |= v[j];
            }
            ans = min(ans, xorr * orr);
        }
        cout << ans << "\n";
    }
    // If xor can be max 1e6
    // There can be 2^20 xor combination with 20 numbers
    // as xor max 1e6, out of 2^20 combination, 2 will must be same
    // If we xor that 2 xor combination that result same, it must be zero
    // (1 ^ 2 ^ 5 ^ 6) ^ (3 ^ 5 ^ 6) = 0, overlapping cancels out, rest result same
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