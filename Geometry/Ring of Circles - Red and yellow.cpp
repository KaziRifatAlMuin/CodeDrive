#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
#define PI acos(-1.0)
#define eps 1e-8

void solve()
{
    double a, b, r;
    cin >> a >> b >> r;
    ll ans = 0;
    for(int n = 3; ; n++){
        double R = r / sin(PI / double(n));
        double rr = R - r;
        if(rr + eps >= a && rr - eps <= b) ans++;
        if(rr - eps > b) break;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock(), cs = 1;
    // cin >> t;
    while(t--){
        // cout << "Case " << cs++ << ": ";
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
