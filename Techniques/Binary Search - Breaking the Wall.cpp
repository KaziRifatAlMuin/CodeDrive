#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector <ll> v(n), a(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    a = v;
    sort(a.begin(), a.end());
    ll low = 1, high = ((a[0]+1)/2 + (a[1]+1)/2);
    ll ans = high, p, q;
    while(low <= high){ // FFFFTTTTT
        bool ok = false;
        ll m = low + (high - low) / 2;
        for(int i = 0, j = 1; j < n && !ok; i++, j++){
            ll a1 = max(v[i], v[j]);
            ll a2 = min(v[i], v[j]);
            a2 = max((a1+1)/2, a2); 
            ll shot = (a1 + a2 + 2) / 3; // Base Case: 2,3
            if(i > 0){ 
                p = v[i-1];
                q = max(0ll, v[i] - 2 * p);
                shot = min(shot, p+q); // 1,2
                q = max(0ll, (v[j] - p + 1) / 2);
                shot = min(shot, p+q); // 1,3
            }
            if(j < n-1){ 
                q = v[j+1];
                p = max(0ll, v[j] - 2 * q);
                // cout << p << " " << q << "\n";
                shot = min(shot, p+q); // 3,4
                p = max(0ll, (v[i] - q + 1) / 2);
                shot = min(shot, p+q); // 2,4
            }
            if(i > 0 && j < n-1){
                q = v[j+1];
                p = v[i-1];
                shot = min(shot, p+q); // 3,4
            }
            if(shot <= m) ok = true;
        }
        if(ok) ans = m, high = m - 1;
        else low = m + 1;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1674/E