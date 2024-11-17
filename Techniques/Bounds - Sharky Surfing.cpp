#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m, L;
    cin >> n >> m >> L;
    map <ll, ll> diff, ind;
    set <ll> px;
    vector <ll> v(m);
    priority_queue <ll> pq;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        diff[y] = (y - x);
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[i] = y;
        ind[x] = i;
        px.insert(x);
    }
    bool ok = true;
    ll sum = 0, last = -1, ans = 0;
    for(auto [r, d] : diff){
        auto it = px.upper_bound(r);
        ll lim;
        if(it != px.begin()){
            --it;
            lim = ind[*it];
        }
        else lim = last;
        for(int i = last + 1; i <= lim; i++){
            pq.push(v[i]);
        }
        last = lim;
        while(sum <= d && !pq.empty()){
            sum += pq.top();
            pq.pop();
            ans++;
        }
        if(sum <= d){
            ok = false;
            break;
        }
    }
    if(ok) cout << ans << "\n";
    else cout << -1 << "\n";
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
// https://codeforces.com/contest/2037/problem/D