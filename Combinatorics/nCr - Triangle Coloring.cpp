#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 7, mod = 998244353;

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

int f[N], invf[N];

void pre() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r) {
    if (n < r or n < 0) return 0;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}

void solve() {
    int n;
    cin >> n;
    ll ans = 1, a;
    multiset <ll> st;
    for(int i = 1; i <= n; i++){
        cin >> a;
        st.insert(a);
        if(i % 3 == 0){
            ans = (ans * st.count(*st.begin())) % mod;
            st.clear();
        }
    }
    ans = (ans * nCr(n/3, n/6)) % mod;
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    //cin >> t;
    pre();
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1795/problem/D