#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x, m, xx, y, ans = 0;
    cin >> x >> m;
    set <ll> st;
    ll maxi = x + m, mini = m - x;
    for(ll y = 1; y <= min(m,x); y++){
        xx = x ^ y;
        if(xx % x == 0 || xx % y == 0){
            // cout << x << " " << y << " " << xx << "\n";
            ans++;
            st.insert(xx);
        }
    }
    if(m > x){
        if(mini > x){
            ans += ((mini / x) - 1);
        }
        // cout << ans << "\n";
        for(ll xx = max(mini+1, x+1); xx <= maxi; xx++){
            y = x ^ xx;
            if((xx % x == 0 || xx % y == 0) && y > 0 && y <= m && st.count(xx) == 0){
                ans++;
                // cout << x << " " << y << " " << xx << "\n";
            }
        }
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
// https://codeforces.com/contest/2039/problem/C2
/*
Key Notes :
- All xor values are unique
- after x up to m, we get all values of xor upto m-x and maximum m+x
*/