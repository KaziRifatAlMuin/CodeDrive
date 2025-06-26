#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7, mod = 998244353;

ll cnt[N+7];

ll permute3(ll n){
    return n * (n-1) * (n-2);
}

void solve()
{
    int n;
    cin >> n;
    vector <ll> v(n), temp;
    for(int i = 0; i < n; i++) cin >> v[i], cnt[v[i]]++, temp.push_back(v[i]);
    ll ans = 0;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for(auto x : temp){
        if(cnt[x] >= 3) ans += permute3(cnt[x]);
    }
    for(auto x : v){
        for(ll b = 2; x*b < N && x*b*b < N; b++){
            ans += (cnt[x*b] * cnt[x*b*b]);
        }
    }
    cout << ans << "\n";
    for(auto x : temp) cnt[x] = 0;
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
// https://codeforces.com/problemset/problem/1822/G1