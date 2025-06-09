#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll up1, up2, down;
    up1 = n * v[n-1] - v[0];
    up2 = n * v[0] - v[n-1];
    down = n * n - 1;
    if(up1 % down == 0 && up2 % down == 0){
        bool ok = true;
        ll x1 = up1 / down;
        ll x2 = up2 / down;
        for(int i = 0; i < n; i++){
            if(x1 * (i+1) + x2 * (n-i) != v[i]) ok = false;
        }
        // cout << x1 << " " << x2 << " ";
        if(x1 >= 0 && x2 >= 0 && ok) cout << "YES\n";
        else cout << "NO\n";
    }
    else cout << "NO\n";
}

// int D = a1 * b2 - a2 * b1, Dx = b1 * c2 - b2 * c1, Dy = c1 * a2 - c2 * a1;
// if (D) { double x = Dx * 1.0 / D, y = Dy * 1.0 / D; /* x and y are the solutions */ }


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
// https://codeforces.com/contest/2117/problem/D