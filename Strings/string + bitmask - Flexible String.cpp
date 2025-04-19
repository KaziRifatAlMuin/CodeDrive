#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
#define CheckBit(x, k) ((x) & (1ll << (k)))

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b, c;
    cin >> a >> b;
    set <char> st;
    for(auto x : a) st.insert(x);
    string s;
    for(auto x : st) s += x;
    map <char, int> mp;
    for(int i = 0; i < s.size(); i++) mp[s[i]] = i;
    int diff = st.size(); k = min(k, diff);
    ll ans = 0;
    for(int mask = 0; mask < (1 << diff); mask++){
        c = a;
        if(__builtin_popcount(mask) <= k){
            for(int i = 0; i < n; i++){
                if(CheckBit(mask, mp[a[i]])) c[i] = b[i];
            }
        }
        ll sub = 0, cur = 0;
        for(int i = 0; i < n; i++){
            if(c[i] == b[i]) cur++;
            else{
                sub += (cur * (cur + 1) / 2);
                cur = 0;
            }
        }
        sub += (cur * (cur + 1) / 2);
        ans = max(ans, sub);
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
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1778/problem/C