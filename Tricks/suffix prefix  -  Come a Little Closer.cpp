#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e16 + 7;

void solve() {
    ll n;
    cin >> n;
    vector <ll> x(n+1), y(n+1);
    vector <ll> Xpremin(n+2, inf), Xsufmin(n+2, inf), Ypremin(n+2, inf), Ysufmin(n+2, inf);
    vector <ll> Xpremax(n+2, -inf), Xsufmax(n+2, -inf), Ypremax(n+2, -inf), Ysufmax(n+2, -inf);
    ll ans = 1e18;
    if(n == 1) ans = 1;
    for(ll i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        Xpremax[i] = max(Xpremax[i-1], x[i]);
        Ypremax[i] = max(Ypremax[i-1], y[i]);
        Xpremin[i] = min(Xpremin[i-1], x[i]);
        Ypremin[i] = min(Ypremin[i-1], y[i]);
    }
    for(ll i = n; i >= 1; i--){
        Xsufmax[i] = max(Xsufmax[i+1], x[i]);
        Ysufmax[i] = max(Ysufmax[i+1], y[i]);
        Xsufmin[i] = min(Xsufmin[i+1], x[i]);
        Ysufmin[i] = min(Ysufmin[i+1], y[i]);
    }
    for(ll i = 1; i <= n; i++){
        ll xmax = max(Xpremax[i-1], Xsufmax[i+1]);
        ll xmin = min(Xpremin[i-1], Xsufmin[i+1]);
        ll ymax = max(Ypremax[i-1], Ysufmax[i+1]);
        ll ymin = min(Ypremin[i-1], Ysufmin[i+1]);
        ll w = xmax - xmin + 1;
        ll h = ymax - ymin + 1;
        ll coins = w * h;
        if(coins == (n - 1)) coins += min(w, h);
        ans = min(ans, coins);
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
// https://codeforces.com/contest/2114/problem/D