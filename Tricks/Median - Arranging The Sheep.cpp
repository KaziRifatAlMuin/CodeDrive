#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector <int> v, sheep;
    for(int i = 0; i < n; i++){
        if(s[i] == '*') v.push_back(i+1);
    }
    int m = v.size();
    if(m == 0){
        cout << 0 << "\n";
        return;
    }
    int mid = v[(m - 1) / 2]; // median gives lowest absolute difference
    for(int k = mid - ((m-1)/2), j = 0; j < m; j++, k++) sheep.push_back(k);
    ll ans = 0;
    for(int i = 0; i < m; i++){
        ans += abs(v[i] - sheep[i]);
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
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1520/E