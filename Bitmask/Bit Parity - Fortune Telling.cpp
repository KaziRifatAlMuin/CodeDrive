#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll odd = 0;
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        if(a & 1) odd++;
    }
    // Both + and ^ changes parity if done with odd
    if(odd & 1){ // parity change
        if(x % 2 != y % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
    else{ // parity same
        if(x % 2 == y % 2) cout << "Alice\n";
        else cout << "Bob\n";
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
// https://codeforces.com/problemset/problem/1634/B