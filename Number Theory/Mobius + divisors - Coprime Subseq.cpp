#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7, mod = 1e9 + 7;

ll cnt[N];  // cnt[x] = frequency of x in the input
ll d[N];    // d[i]   = # of input elements divisible by i
ll f[N];    // f[i]   = # of non-empty subseq’s all divisible by i
ll mob[N];  // Möbius function μ(i)

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

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    mob[1] = 1;
    for(int i = 1; i < N; i++){
        for(int j = i + i; j < N; j += i){
            mob[j] -= mob[i];
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[i] += cnt[j];
        }
    }
    ll ans = 0;
    for(int i = 1; i < N; i++){
        if(d[i] == 0 || mob[i] == 0) continue;  // nothing to add/subtract
        f[i] = (power(2, d[i]) - 1 + mod) % mod; // number of non-empty subsequences from d[i]
        ans = ((ans + mob[i] * f[i]) % mod + mod) % mod; // inclusion–exclusion using mobius
    }
    cout << ans << "\n";
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
// https://codeforces.com/contest/803/problem/F