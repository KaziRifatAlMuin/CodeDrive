#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, char>> v = {{n, '0'}, {m, '1'}};
    sort(v.begin(), v.end());
    if(k > max(n, m) || k < abs(m - n)) cout << -1 << "\n";
    else{
        deque <char> ans1, ans2;
        auto [a, ca] = v[0];
        auto [b, cb] = v[1];
        while(a > 0){
            ans1.push_back(cb); 
            ans1.push_back(ca); 
            a--; b--;
        }
        while(b > 0){
            ans2.push_back(cb); 
            b--;
        }
        ll d = k - abs(n - m);
        for(int i = 0, p = 0, q = 2*min(n,m) - 1; i < d; i++, p += 2, q -= 2){
            ans1.pop_back();
            ans1.pop_back();
            ans2.push_front(cb); 
            ans1.push_front(ca); 
        }
        for(auto x : ans1) cout << x;
        for(auto x : ans2) cout << x;
        cout << "\n";
    }
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
// https://codeforces.com/contest/2065/problem/E