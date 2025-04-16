#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <int> deg(n+1, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
    }
    vector <bool> isleaf(n+1, false);
    for(int i = 2; i <= n; i++){
        if(deg[i] == 1) isleaf[i] = true;
    }
    string s;
    int cnt0 = 0, cnt1 = 0, cntx = 0, ans = 0, extra = 0;
    cin >> s;
    for(int i = 1; i < n; i++){
        if(isleaf[i+1]){
            if(s[i] == '0') cnt0++;
            else if(s[i] == '1') cnt1++;
            else cntx++;
        }
        else if(s[i] == '?') extra++;
    }
    if(s[0] == '0') ans = cnt1 + (cntx + 1) / 2;
    else if(s[0] == '1') ans = cnt0 + (cntx + 1) / 2;
    else ans = (cnt0 == cnt1 && extra & 1) ? cnt0 + (cntx + 1) / 2 : max(cnt0, cnt1) + cntx / 2;
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
// https://codeforces.com/problemset/problem/2006/A