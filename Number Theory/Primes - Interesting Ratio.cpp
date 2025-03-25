#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e7 + 7;

bool NotPrime[N+10];
vector <int> primes;
ll cnt[N+10];

void seive()
{
    NotPrime[1] = 1; NotPrime[0] = 1;
    cnt[0] = 0, cnt[1] = 0;
    for(ll i = 4; i < N; i += 2) NotPrime[i] = 1;
    for(ll i = 3; i * i < N; i += 2){
        if(!NotPrime[i]){
            for(ll j = i * i; j < N; j += (i+i)) NotPrime[j] = 1;
        }
    }
    for(ll i = 2; i < N; i++){
        if(!NotPrime[i]){
            // primes.emplace_back(i);
            cnt[i] = cnt[i-1] + 1;
        }
        else cnt[i] = cnt[i-1];
    }
}


void solve()
{
    ll ans = 0;
    ll n; cin >> n;
    for(int i = 1; i <= n; i++){
        ans += cnt[n/i];
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    seive();
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2091/problem/E