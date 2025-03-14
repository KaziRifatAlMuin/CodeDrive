#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        if(a[i-1] % a[i] != 0){
            cout << 0 << "\n";
            return;
        }
    }
    vector <ll> primes; // prime factors
    {
        ll x = a[0];
        for(ll i = 2; i * i <= x; i++){
            if(x % i == 0){
                ll v = 1;
                while(x % i == 0) x /= i, v *= i;
                primes.push_back(i);
            }
        }
        if(x > 1) primes.push_back(x);
    }

    ll ans = 1;
    for(int i = 1; i < n; i++){
        ll r = a[i-1] / a[i];
        vector <ll> lost;
        for(auto p : primes){
            if(r % p == 0){
                ll v = 1;
                while(r % p == 0) r /= p, v *= p;
                lost.push_back(p);
            }
        }

        // Inclusion - Exclusion
        ll k = lost.size(), now = 0; 
        for(int j = 0; j < (1 << k); j++){
            ll v = a[i], cnt = 0;
            for(int e = 0; e < k; e++){
                if(j & (1 << e)){
                    v *= lost[e];
                    cnt++;
                }
            }
            if(cnt & 1) now -= m / v;
            else now += m / v;
        }
        ans = (ans * now) % mod;
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
// https://codeforces.com/contest/1750/problem/D