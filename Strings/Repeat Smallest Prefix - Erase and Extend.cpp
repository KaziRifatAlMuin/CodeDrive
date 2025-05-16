#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector <string> str;
    int len = 1; // “repeat‑smallest‑prefix” trick:
    for(int i = 1; i < n; i++){
        if(s[i] < s[i % len]) len = i + 1;  // strictly smaller character, so include till i
        else if(s[i] > s[i % len]) break;
    }
    string tmp = s.substr(0, len);
    string ans = tmp;
    while(ans.size() < k) ans += tmp;
    while(ans.size() > k) ans.pop_back();
    cout << ans << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1537/problem/E2