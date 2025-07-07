#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b){
    return (a / __gcd(a,b)) * b;
}

void solve(){
    int n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    set <ll> xx;
    for(int i = n-2; i >= 0; i--){
        if(v[i+1] % v[i] == 0) continue;
        else{
            ll g = __gcd(v[i+1], v[i]);
            xx.insert(v[i] / g);
            // cout << i << " " << v[i]/g << "\n";
            v[i] = g;
        }
    }
    ll ans = 1;
    for(auto x : xx) ans = lcm(ans, x);
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
// https://codeforces.com/contest/2124/problem/C