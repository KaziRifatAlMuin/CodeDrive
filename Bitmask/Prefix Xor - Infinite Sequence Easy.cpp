#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <ll> v, p;
ll n;

ll run(ll m){
    if(m <= n+1) return p[m];
    ll term = m - n - 1, ans = 0;
    if(m & 1){
        if(term & 1) ans = run((m-1)/2 + 1);
        else ans = run((m-1)/2 + 1) ^ run((n+1)/2 + 1);
    }
    else{
        if(term & 1) ans = run((n+1)/2 + 1);
        else ans = 0;
    }
    return ans ^ p[n+1];
}

void solve() {
    ll l, r;
    cin >> n >> l >> r;
    v.assign(n+1,0);
    p.assign(n+2,0); //prexor
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        p[i+1] = p[i] ^ v[i];
    } // a_m = p_m ^ p_m+1
    cout << (run(l) ^ run(l+1)) << "\n";
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
// https://codeforces.com/contest/2071/problem/D1