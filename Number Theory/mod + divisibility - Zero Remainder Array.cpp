#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <ll> v(n), add(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        add[i] = (k - (v[i] % k)) % k; // a[i] = 13, k = 8; add[i] = 8 - (13 % 8) = 8 - 5 = 3; 
        // a[i] = 8, add[i] = 8 - (8 % 8) = 8, for this mod with k again
    }
    map <ll, ll> mp;
    ll ans = 0;
    for(auto x : add){
        if(!mp[x]) mp[x] = x;
        else mp[x] += k;
        ans = max(ans, mp[x]);
    }
    if(ans != 0) ans++;
    cout << ans << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1374/D