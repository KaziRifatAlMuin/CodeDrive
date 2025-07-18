#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b){
    return (a / __gcd(a,b)) * b;
}

void solve()
{
    int n;
    cin >> n;
    vector <ll> p(n), s(n), v(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = n-1; i >= 0; i--){
        v[i] = lcm(p[i], s[i]);
    }
    bool ok = true;
    ll g = 0;
    for(int i = 0; i < n; i++){
        g = __gcd(g, v[i]);
        if(g != p[i]) ok = false;
    }
    g = 0;
    for(int i = n-1; i >= 0; i--){
        g = __gcd(g, v[i]);
        if(g != s[i]) ok = false;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock(), cs = 1;
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2126/problem/E