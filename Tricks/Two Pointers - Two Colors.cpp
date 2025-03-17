#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> k >> n;
    vector <ll> v(n), pre(n+1);
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> v[i], v[i] = min(v[i], k - 1);
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + v[i-1];
    ll low = 0, high = n - 1;
    while(low < high){
        if(v[low] + v[high] >= k){
            ll cnt = high - low; // all element in range [low,high] satisfy the condition
            ll add = v[high] * cnt + (pre[high] - pre[low]);
            ll minus = k * cnt;
            ans += (add - minus + cnt) * 2;
            // cout << add << " " << minus << " " << (add - minus + cnt) * 2 << "\n";
            high--;
        }
        else{
            low++;
        }
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
// https://codeforces.com/contest/2075/problem/C