#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
#define PowerOf2(v) (v && !(v & (v - 1)))
#define CheckBit(x, k) (((x) >> (k)) & 1ll)

ll res(ll i){
    ll a = i, b = i - 1, ans = 0;
    while(a > 0 || b > 0){
        if(a % 2 != b % 2) ans++;
        a /= 2; b /= 2;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < 64; i++){
        if(CheckBit(n, i)) ans += ((1ll << (i + 1)) - 1);
    }
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
// https://codeforces.com/problemset/problem/1362/C