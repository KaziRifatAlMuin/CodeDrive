#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector <ll> v(n), cnt(n+1), pre(n+1);
    for(int i = 0; i < n; i++) cin >> v[i];
    cnt[0] = 1; pre[0] = 1;
    for(int i = 1; i < n; i++){
        cnt[i] = cnt[i-1] + 1;
        if(v[i-1] != v[i]) cnt[i] += i;
        pre[i] = pre[i-1] + cnt[i];
    }
    ll ans = pre[n-1];
    while(m--){
        ll pos, x;
        cin >> pos >> x;
        pos--;
        ll right = n - pos;
        if(pos-1 >= 0 && v[pos-1] != v[pos] && v[pos-1] == x) ans -= (right) * pos;
        if(pos+1 < n && v[pos+1] != v[pos] && v[pos+1] == x) ans -= (right-1) * (pos+1);
        if(pos-1 >= 0 && v[pos-1] == v[pos] && v[pos-1] != x) ans += (right) * pos;
        if(pos+1 < n && v[pos+1] == v[pos] && v[pos+1] != x) ans += (right-1) * (pos+1);
        v[pos] = x;
        cout << ans << "\n";
    }
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
// https://codeforces.com/problemset/problem/1715/C