#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll low = 1, high = n+2, ans = 0;
    while(low <= high){
        bool ok = false; // TTTTTFFFFF
        ll mid = low + (high - low) / 2;
        ll mex = 0, sub = 0;
        vector <bool> seen(mid+2);
        for(int i = 0; i < n; i++){
            if(v[i] <= mid) seen[v[i]] = 1;
            while(seen[mex]){
                mex++;
                if(mex == mid){
                    sub++;
                    mex = 0;
                    seen.assign(mid+2, 0);
                    break;
                }
            }
        }
        if(sub >= k) ok = true;
        if(ok) ans = mid, low = mid + 1;
        else high = mid - 1;
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
// https://codeforces.com/contest/2093/problem/E