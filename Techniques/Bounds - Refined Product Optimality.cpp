#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return result;
}

ll modinv(ll a) { return power(a, mod - 2);}

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n), b(n), sa, sb, v;
    vector <pair<int, int>> aa, bb;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sa = a, sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans = (ans * min(sa[i], sb[i])) % mod;
    }
    v.push_back(ans);

    while(q--){
        ll o, x, prev, now;
        cin >> o >> x;
        x--;
        if(o == 1){
            ll y = a[x];
            a[x]++;
            auto it = upper_bound(sa.begin(), sa.end(), y) - sa.begin();
            if(it != 0) it--;
            prev = min(sa[it], sb[it]);
            sa[it]++;
            now = min(sa[it], sb[it]);
        }
        else{
            ll y = b[x];
            b[x]++;
            auto it = upper_bound(sb.begin(), sb.end(), y) - sb.begin();
            if(it != 0) it--;
            prev = min(sa[it], sb[it]);
            sb[it]++;
            now = min(sa[it], sb[it]);
        }

        ans = (((ans * modinv(prev)) % mod) * now) % mod;
        v.push_back(ans);
    }

    for(auto x : v){
        cout << x << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2053/problem/D