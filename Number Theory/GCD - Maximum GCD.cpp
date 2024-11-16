#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        ans = __gcd(ans, v[i]);
    }
    sort(v.begin(), v.end());
    int a = v[0], b = v[1], c = v[0]/2, d =  v[1]/2;
    ans = max(ans,max(__gcd(a,d), min(c,d)));
    if(d > a) ans = max(ans, a);
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/problem/QOJ-5465