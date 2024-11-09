#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    ld a, b, c;
    cin >> a >> b >> c;
    ld s = (a + b + c) / 2.0;
    ld top = 16 * s * (s - a) * (s - b) * (s - c);
    ld down = 16 * s * s;
    ll x = top, y = down;
    ll gcd = __gcd(x,y);
    x /= gcd;
    y /= gcd;
    cout << x << "/" << y << "\n";
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