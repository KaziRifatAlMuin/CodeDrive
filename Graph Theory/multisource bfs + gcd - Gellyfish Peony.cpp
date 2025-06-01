#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5007, inf = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector <int> v(n), dist(N+1, inf);
    // dist[i] = minimum # of operation to get an elem = i
    int g = 0, cnt = 0;
    for(int i = 0; i < n; i++) cin >> v[i], g = __gcd(g, v[i]);
    queue <int> q;
    for(int i = 0; i < n; i++) {
        if(v[i] == g) cnt++;
        q.push(v[i]);
        dist[v[i]] = 0;
    }
    if(cnt > 0){
        cout << n - cnt << "\n";
        return;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // multisource bfs
    while(dist[g] == inf){ 
        int cur = q.front();
        q.pop();
        for(auto it : v) {
            int x = __gcd(cur, it);
            if(dist[x] == inf){
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
    }
    cout << dist[g] + (n-1) << "\n";
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
// https://codeforces.com/contest/2116/problem/C