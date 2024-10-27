#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector <pair <int,int>> v;
    multiset <int> free;
    for(int i = 0; i < k; i++) free.insert(0);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(auto [b,a] : v){
        auto it = free.upper_bound(a);
        if(it == free.begin()) continue;
        it--;
        free.erase(it);
        free.insert(b);
        ans++;
    }
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
// https://cses.fi/problemset/task/1632/