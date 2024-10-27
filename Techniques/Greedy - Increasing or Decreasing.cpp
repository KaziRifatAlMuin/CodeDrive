#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n+1), pos(n+1), temp(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector <tuple<int, int, char>> ans;
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++) pos[v[i]] = i;
    ans.push_back({1, n, 'I'});
    for(int i = 1; i < n; i++){
        int target = pos[b[i]];
        if(target == i) continue;
        else if(v[target] < v[i]){
            sort(v.begin() + i, v.begin() + target + 1);
            ans.push_back({i, target, 'I'});
        }
        else{
            sort(v.begin() + i, v.begin() + target + 1);
            reverse(v.begin() + i, v.begin() + target + 1);
            ans.push_back({i, target, 'D'});
        }
        for(int i = 1; i <= n; i++) pos[v[i]] = i;
    }
    cout << ans.size() << "\n";
    for(auto [x,y,z] : ans){
        cout << x << " " << y << " " << z << "\n";
    }
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
// https://codeforces.com/gym/103260/problem/J