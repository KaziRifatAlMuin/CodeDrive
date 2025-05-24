#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector <int> v(n), L(n), R(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> L[i] >> R[i];
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int cur = 0, h = 0, add = 0;
    for(int i = 0; i < n; i++){
        if(v[i] != -1) cur += v[i];
        pq.push({R[i] - cur, i}); // max additional climb allowed at or after index i
    }
    // min heap to get the bottleneck at every step
    bool ok = true;
    for(int i = 0; i < n; i++){
        while(!pq.empty() && pq.top().second < i) pq.pop();
        if(v[i] == -1){
            if(!pq.empty() && add + 1 <= pq.top().first) v[i] = 1, add++;
            else v[i] = 0;
        }
        h += v[i];
        if(h < L[i] || h > R[i]) ok = false;
    }
    if(!ok) cout << -1 << "\n";
    else{
        for(auto x : v) cout << x << " ";
        cout << "\n";
    }
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2110/problem/C