#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll nc2(ll n) {return n * (n - 1) / 2;}
ll nc3(ll n) {return n * (n - 1) * (n - 2) / 6;}
ll nc4(ll n) {return n * (n - 1) * (n - 2) * (n - 3) / 24;}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    if(k >= 2) ans += nc2(n);
    if(k >= 3) ans += 2 * nc3(n);
    if(k >= 4) ans += 9 * nc4(n);
    cout << ans << "\n";
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
// https://codeforces.com/problemset/problem/888/D