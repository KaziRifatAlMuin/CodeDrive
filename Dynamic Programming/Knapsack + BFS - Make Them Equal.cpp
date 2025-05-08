#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 7;

vector <int> cost;

void pre(){
    cost.assign(N, INT_MAX);
    queue<int> q;
    cost[0] = cost[1] = 0;
    q.push(1); // BFS
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int x = 1; x <= u; x++){
            int v = u + u/x;
            if(v >= N) continue;
            if(cost[v] == INT_MAX){
                cost[v] = cost[u] + 1;
                q.push(v);
            }
        }
    }
    // cout << *max_element(cost.begin(), cost.end()) << "\n"; // max = 12
}

void solve(){
    int n, k;
    cin >> n >> k;
    k = min(k, 12 * n);
    vector <int> b(n), c(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<ll> dp(k+1, 0); // 0/1 knapsack on weights = cost[b[i]], values = c[i]
    for(int i = 0; i < n; i++){
        int wt = cost[b[i]];
        if(wt > k) continue;
        for(int w = k; w >= wt; w--){
            dp[w] = max(dp[w], dp[w - wt] + c[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1633/D