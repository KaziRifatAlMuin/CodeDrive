#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check1(const vector<int>& v, int k) {
    int n = v.size();
    vector<int> pre(n+1, 0);
    for(int i = 0; i < n; i++){
        pre[i+1] = pre[i] + (v[i] <= k ? +1 : -1);
    }
    int cnt = 0, l = 0;
    for(int r = 1; r < n; r++){
        if(pre[r] >= 0 && v[r-1] <= k){
            cnt++;
            l = r;
        }
    }
    return cnt >= 2;
}

bool check2(const vector<int>& v, int k) {
    int n = v.size();
    vector<int> pre(n+1, 0);
    for(int i = 0; i < n; i++){
        pre[i+1] = pre[i] + (v[i] <= k ? +1 : -1);
    }
    int cnt = 0, l = 0, r = n;
    for(int i = 1; i < n - 1; i++){
        if(pre[i] >= 0){
            cnt++;
            l = i;
            break;
        }
    }
    for(int i = n - 1; i > l; i--){
        if(pre[n] - pre[i] >= 0){
            cnt++;
            r = i;
            break;
        }
    }
    return cnt >= 2;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    bool ok = check1(v, k) | check2(v, k);
    reverse(v.begin(), v.end());
    ok = ok || check1(v, k);
    cout << (ok ? "YES\n" : "NO\n");
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
// https://codeforces.com/contest/2103/problem/C