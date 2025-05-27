#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int spf[N];
vector <int> primes;

void sieve() {
    for(int i = 1; i < N; i++) spf[i] = i;
    for(int i = 2; 1ll * i * i < N; i++) {
        if(spf[i] == i) { // i is prime
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(spf[i] == i) primes.push_back(i);
    }
}

vector <pair<ll,ll>> factor(ll n) {
    vector <pair<ll,ll>> fact;
    for(auto p : primes){
        if(1ll * p * p > n) break;
        if(n % p == 0){
            ll power = 0;
            while(n % p == 0){
                n /= p;
                power++;
            }
            fact.push_back({p, power});
        }
    }
    if(n > 1) fact.push_back({n, 1});
    return fact;
}

void solve(){
    int n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    map<ll, multiset<ll>> powerlist;
    map <ll,ll> cnt;
    for(int i = 0; i < n; i++){
        ll cur = v[i];
        for(auto p : primes){
            if(1ll * p * p > cur) break;
            if(cur % p == 0){
                ll power = 0;
                cnt[p]++;
                while(cur % p == 0){
                    cur /= p;
                    power++;
                }
                powerlist[p].insert(power);
            }
        }
        if(cur > 1) powerlist[cur].insert(1), cnt[cur]++;
    }
    ll ans = 1;
    for(auto &[p, powers] : powerlist) {
        if(cnt[p] <= n - 2) continue;
        else{
            auto it = powers.begin();
            if(cnt[p] == n) it++;
            ll second_smallest = *it;
            ans *= pow(p, second_smallest);
        }
    }
    cout << ans << "\n";
}
    

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    sieve();
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1349/A