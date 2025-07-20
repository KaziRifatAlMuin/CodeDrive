#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf =  1e8;

void solve()
{
    int n, k;
    cin >> n;
    vector <tuple<ll,ll,ll>> v1, v2, xy;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        xy.push_back({x, y, i+1});
    }
    sort(xy.begin(), xy.end());
    for(int i = 0; i < n; i++){
        auto [x, y, id] = xy[i];
        if(i < n/2) v1.push_back({y, x, id});
        else v2.push_back({y, x, id});
    }
    sort(v1.begin(), v1.end());
    sort(v2.rbegin(), v2.rend());
    for(int i = 0; i < n/2; i++){
        cout << get<2>(v1[i]) << " " << get<2>(v2[i]) << "\n";
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
// https://codeforces.com/contest/2122/problem/C