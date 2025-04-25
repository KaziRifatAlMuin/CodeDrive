#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector <ll> v(n+1), pos(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        int target = pos[k];
        int m = (l + r) / 2;
        if(target < l || target > r) cout << -1 << " ";
        else{
            bool ok = true;
            ll ans = 0, big = 0, small = 0, bigcnt = n-k, smallcnt = k-1;
            while(l <= r){
                m = (l + r) / 2;
                if(m == target){
                    ok = true;
                    break;
                }
                if(target < m){ // left
                    r = m - 1;
                    if(k > v[m]) big++;
                    else bigcnt--;
                }
                else{ // right
                    l = m + 1;
                    if(k < v[m]) small++;
                    else smallcnt--;
                }
            }
            ans = max(big, small) * 2;
            if(ok && big <= bigcnt && small <= smallcnt) cout << ans << " ";
            else cout << -1 << " ";
        }
    }
    cout << "\n";
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
// https://codeforces.com/contest/2106/problem/E