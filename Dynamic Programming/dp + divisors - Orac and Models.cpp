#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector <int> divs[N];

void pre(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j+=i){
            divs[j].push_back(i);
        }
    }
}

void solve(){
    ll n; cin >> n;
    vector <ll> v(n+1);
    for(ll i = 1; i <= n; i++) cin >> v[i];
    vector <ll> dp(n+1, 1); // max len when end at i
    ll ans = 1;
    for(ll i = 1; i <= n; i++){
        for(auto j : divs[i]){
            if(v[j] < v[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1350/problem/B