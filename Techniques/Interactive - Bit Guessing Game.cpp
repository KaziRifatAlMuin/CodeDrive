#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ask(ll x){
    cout << "- " << x << "\n";
    cout.flush();
    ll bit; cin >> bit;
    return bit;
}

void solve() {
    ll ans = 0;
    ll prev; cin >> prev;
    ll kaffara = 0, now;
    for(ll i = 0; i < 30 && prev > 0; i++){
        now = ask((1 << i));
        if(prev - now == 1) ans += (1 << i), prev = now;
        else{
            ll m = i + 1 + (now - prev); // bit i to m all becomes 1
            ans += (1 << m); // Actual bit added
            kaffara = ((1 << m) - (1 << i)); 
            prev = ask(kaffara); // all 1's subtracted
            i = m; // up to m'th bit done
        }
    }
    cout << "! " << ans << "\n";
    cout.flush();
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
// https://codeforces.com/contest/1780/problem/D