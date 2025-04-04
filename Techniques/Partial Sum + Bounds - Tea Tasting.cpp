#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector <ll> a(n), b(n), pre(n+1), part(n+2), time(n+1), left(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i], pre[i+1] = pre[i] + b[i];
    for(int i = 0; i < n; i++){
        int q = upper_bound(pre.begin(), pre.end(), pre[i] + a[i]) - pre.begin() - 1;
        if(q >= n) q = n;
        else left[q] += (a[i] - (pre[q] - pre[i]));
        part[i]++; part[q]--;
    }
    for(int i = 0; i < n; i++) time[i+1] = time[i] + part[i];
    for(int i = 0; i < n; i++) cout << time[i+1] * b[i] + left[i] << " ";
    cout << "\n";
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
// https://codeforces.com/contest/1795/problem/C