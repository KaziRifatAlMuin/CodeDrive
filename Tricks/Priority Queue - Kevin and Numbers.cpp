#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    ll suma = 0, sumb = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        suma += a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        sumb += b[i];
    }
    if(suma != sumb){
        cout << "NO\n";
        return;
    }
    bool ok = true;

    priority_queue <ll> pq1, pq2;

    for(auto x : a) pq1.push(x);
    for(auto x : b) pq2.push(x);
    while(!pq1.empty() && !pq2.empty()){
        ll have = pq1.top();
        ll need = pq2.top();
        pq2.pop();
        if(have == need){
            pq1.pop();
            continue;
        }
        ll p = need/2, q = need - need/2;
        if(p < 1 || q < 1) break;
        pq2.push(p);
        pq2.push(q);
        if(pq2.size() > pq1.size()) break;
    }
    if(pq1.empty() && pq2.empty()) cout << "YES\n";
    else cout << "NO\n";
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
// https://codeforces.com/contest/2061/problem/D                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   