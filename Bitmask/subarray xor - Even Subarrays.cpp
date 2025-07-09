#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll odd = 0;
    vector <ll> pre(n+1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] ^ v[i-1];
    for(ll k = 0; k * k <= 2*n; k++){
        vector <ll> mp(4*n, 0); 
        ll cnt = 0, s = k * k;
        // pre[r] ^ pre[l-1] == s
        // pre[l-1] = pre[r] ^ s (count how many and add it)
        mp[0]++; // so that I can take single element with value s
        for(int i = 1; i <= n; i++){
            cnt += mp[pre[i] ^ s];
            mp[pre[i]]++;
        }
        odd += cnt;
    }
    cout << (n * (n+1) / 2) - odd << "\n";
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
// https://codeforces.com/contest/1731/problem/C