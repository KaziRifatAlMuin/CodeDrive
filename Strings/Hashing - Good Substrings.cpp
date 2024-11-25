#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    vector <pair <ll,ll>> v;
    string s, isGood;
    cin >> s >> isGood;
    int k; cin >> k;
    int n = s.size();
    ll m1 = 1e9 + 57, m2 = 1e9 + 9;
    ll p1 = 31, p2 = 53;
    for(int i = 0; i < n; i++){
        string sub = "";
        int bad = 0;
        ll pp1 = p1, pp2 = p2;
        ll h1 = 0;
        ll h2 = 0;
        for(int j = 0; j < n - i; j++){
            if(isGood[s[i + j] - 'a'] == '0') bad++;
            if(bad > k) break;
            sub = sub + s[i + j];
            h1 = ((h1 * p1) % m1 + ((s[i+j] - 'a' + 1) * p1) % m1) % m1;
            h2 = ((h2 * p2) % m2 + ((s[i+j] - 'a' + 1) * p2) % m2) % m2;
            v.push_back({h1, h2});
        }
    }
    ll sz = v.size();
    sort(v.begin(), v.end());
    ll ans = sz;
    for(int i = 0; i < sz - 1; i++){
        if(v[i].first == v[i+1].first && v[i].second == v[i+1].second) ans--;
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
// https://codeforces.com/problemset/problem/271/D