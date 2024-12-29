#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

pair <ll, ll> run(ll len){
    if(len < k) return {0, 0};
    auto [ans, term] = run(len/2);
    ll m = (len + 1) / 2;
    if(len & 1){
        return {ans * 2 + m * term + m, term * 2 + 1};
    }
    else{
        return {ans * 2 + m * term, term * 2};
    }
}

void solve() {
    cin >> n >> k;
    cout << run(n).first << "\n";

    // Wrong Approch During Contest, It doesn't follow series
    // ll p = 1, ans = 0, len = n, d = n + 1;
    // while(len >= k){
    //     ll a = (len + 1) / 2;
    //     ll sum = (p * ((2 * a + ((p - 1) * d)))) / 2;
    //     if(len & 1) {
    //         ans += sum;
    //     }
    //     // ans += sum;
    //     cout << len << " " << a << " " << p << " " << d << " -> " << sum << " " << ans << "\n";
    //     p *= 2;
    //     d = a;
    //     // if(len % 2 == 0) d++;
    //     len /= 2;
    // }
    // cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2053/problem/C