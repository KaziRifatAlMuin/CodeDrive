#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    ll p = 0, m = 0;
    for(auto x : s){
        if(x == '+') p++;
        else m++;
    }
    ll q; cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a == b){
            if(m == p) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        ll up = (p - m) * b;
        ll k = up / (b - a);
        if(up % (b-a) !=0 || k < -m || k > p) cout << "NO\n";
        else cout << "YES\n";
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
// https://codeforces.com/problemset/problem/1776/L