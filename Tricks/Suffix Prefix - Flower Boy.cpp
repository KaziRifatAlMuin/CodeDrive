#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    vector <ll> pre(m+2, inf), suf(m+2, -1);
    pre[0] = -1;
    suf[m+1] = inf;
    ll pos = 0;
    for(int i = 0; i < m; i++){
        while(pos < n && a[pos] < b[i]) pos++;
        if(pos < n) pre[i+1] = pos++; 
    }
    pos = n - 1;
    for(int i = m - 1; i >= 0; i--){
        while(pos >= 0 && a[pos] < b[i]) pos--;
        if(pos >= 0) suf[i+1] = pos--; 
    }
    if(pre[m] < inf) cout << 0 << "\n";
    else{
        ll ans = inf;
        for(int i = 1; i <= m; i++){
            if(pre[i-1] < suf[i+1]) ans = min(ans, b[i-1]);
        }
        if(ans == inf) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}  

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2106/problem/D