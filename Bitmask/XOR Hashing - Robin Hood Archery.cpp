#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

void solve(){
    int n, q;
    cin >> n >> q;
    vector <ll> v(n+1);
    vector <pair<ll,ll>> prexor(n+1);
    map <ll, pair<ll,ll>> hash;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(!hash.count(v[i])) hash[v[i]].first = rnd(0, 1ll << 62), hash[v[i]].second = rnd(0, 1ll << 62);
    }
    for(int i = 1; i <= n; i++){
        prexor[i].first = prexor[i-1].first ^ hash[v[i]].first;
        prexor[i].second = prexor[i-1].second ^ hash[v[i]].second;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        ll x1 = prexor[r].first ^ prexor[l-1].first;
        ll x2 = prexor[r].second ^ prexor[l-1].second;
        cout << ((x1 == 0 && x2 == 0) ? "YES\n" : "NO\n");
    }  
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
// https://codeforces.com/contest/2014/problem/H