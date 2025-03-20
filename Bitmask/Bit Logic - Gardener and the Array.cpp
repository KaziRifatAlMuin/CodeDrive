#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

void solve() {
    ll n;
    cin >> n;
    vector <vector<ll>> v(n);
    map <int, int> cnt;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int c; cin >> c;
            v[i].push_back(c);
            cnt[c]++;
        }
    }
    bool allone = true;
    for(int i = 0; i < n; i++){
        bool one = false;
        for(auto x : v[i]){
            if(cnt[x] == 1) one = true;
        }
        allone &= one;
    }
    // If all has a unique bit, it's never possible
    // otherwise we can take a = all, 
    // and b = all except one number that has no unique bit
    if(allone) cout << "No\n";
    else cout << "Yes\n";
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
// https://codeforces.com/problemset/problem/1775/B