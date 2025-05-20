#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int na, nb, k;
    cin >> na >> nb >> k;
    vector <ll> a(k), b(k), boy(na+1), girl(nb+1);
    for(int i = 0; i < k; i++) cin >> a[i], boy[a[i]]++;
    for(int i = 0; i < k; i++) cin >> b[i], girl[b[i]]++;
    ll ans = 0, rem = k;
    for(int i = 0; i < k; i++){
        boy[a[i]]--, girl[b[i]]--; rem--;
        ans += max(0ll,(rem - boy[a[i]] - girl[b[i]]));
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
// https://codeforces.com/problemset/problem/1475/C