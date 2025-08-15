#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector <ll> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i]; 
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if(n & 1) cout << 1 << "\n";
    else{
        ll a = x[n/2] - x[n/2 - 1] + 1;
        ll b = y[n/2] - y[n/2 - 1] + 1;
        cout << a * b << "\n";
    }
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock(), cs = 1;
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1486/problem/B