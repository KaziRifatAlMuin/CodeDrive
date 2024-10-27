#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector <ll> v(n), pre(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pre[i+1] = pre[i] + v[i];
    }
    map <ll,ll> mp;
    int last = -1, ans = 0, pos = 0;
    for(auto x : pre){
        if(mp.find(x) != mp.end()){
            if(mp[x] >= last){
                ans++;
                last = pos;
            }
        }
        mp[x] = pos;
        pos++;
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
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2033/problem/D
