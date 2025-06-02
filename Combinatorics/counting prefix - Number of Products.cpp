#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector <int> v(n);
    ll neg = 0, ans_neg = 0, cnt_odd = 0, cnt_even = 1;
    // empty prefix is considered even
    // cnt : # of prefixes with odd/even # of neg element
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] < 0) neg++;
        if(neg & 1) ans_neg += cnt_even, cnt_odd++;
        else ans_neg += cnt_odd, cnt_even++;
    }
    cout << ans_neg << " " << (n * (n+1)) / 2 - ans_neg << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1215/B