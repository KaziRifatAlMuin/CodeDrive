#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector <ll> a(n), b(n), diff(n), pre(2 * n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    pre[0] = a[0] - b[0];
    for(int i = 1; i < 2 * n; i++) pre[i] = pre[i-1] + a[i % n] - b[i % n];
    stack <pair<ll,ll>> stk; //  stack for monotonic inc-dec detection
    ll ans = 0;
    for(int i = 0; i < 2 * n; i++){
        while(!stk.empty() && stk.top().first >= pre[i]){
            auto [x, j] = stk.top();
            stk.pop();
            ans = max(ans, i - j);
        }
        stk.push({pre[i], i});
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
// https://codeforces.com/contest/2090/problem/E1