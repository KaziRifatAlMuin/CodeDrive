#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll ans = 1;
    if(n <= m){
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ans = (ans * abs(v[i] - v[j])) % m;
            }
        }
        cout << ans << "\n";
    }
    else{
        cout << "0\n";
    }
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
// https://codeforces.com/problemset/problem/1305/C