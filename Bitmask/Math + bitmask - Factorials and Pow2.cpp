#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e12 + 7;

void solve(){
    ll n;
    cin >> n;
    vector <ll> fact(16);
    fact[0] = 1;
    int ans = 100;
    for(ll i = 1; i <= 15; i++) fact[i] = fact[i-1] * i;
    for(int mask = 0; mask < (1 << 15); mask++){
        ll sum = 0;
        for(int j = 0; j < 15; j++){
            if((mask >> j) & 1) sum += fact[j];
        }
        if(sum <= n){
            ans = min(ans, __builtin_popcount(mask) + __builtin_popcountll(n-sum));
        } // add ll in the end of popcount for long long
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
// https://codeforces.com/problemset/problem/1646/C