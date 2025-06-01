#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    for(int len = n/2; len > 0; len--){
        vector <int> v(n);
        for(int i = 0, j = len; j < n; i++, j++){
            if(s[i] == s[j] || s[i] == '?' || s[j] == '?') v[i] = 1;
        }
        bool ok = false;
        int sum = 0;
        for(int i = 0; i < len; i++) sum += v[i];
        if(sum == len) ok = true;
        for(int i = len; i < n; i++){
            sum = sum + v[i] - v[i-len];
            if(sum == len) ok = true;
        }
        if(ok){
            ans = max(ans, len * 2);
            break;
        }
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
// https://codeforces.com/problemset/problem/1948/D