#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 998244353;

vector<vector<int>> G, level;
vector<ll> dis, dp;
ll max_dis;

void bfs(int n) {
    queue<int> q;
    q.push(n);
    dis[n] = 0;
    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        for(auto child : G[cur_v]){
            if(dis[child] == -1) { 
                q.push(child);
                dis[child] = dis[cur_v] + 1;
                max_dis = max(max_dis, dis[child]);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    G.assign(n + 1, vector<int>());
    dis.assign(n + 1, -1);
    dp.assign(n + 1, 0);

    for(int u = 2; u <= n; u++){
        int v;
        cin >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    max_dis = 0;
    bfs(1);
    // cout << max_dis << "\n";
    level.assign(max_dis + 1, vector<int>());

    for(int i = 1; i <= n; i++){
        level[dis[i]].push_back(i);
        max_dis = max(max_dis, dis[i]);
    }

    ll prev = 0;
    for(int i = max_dis; i >= 0; i--){
        ll temp = 0;
        for(auto x : level[i]){
            if(i == max_dis) dp[x] = 1, prev++;
            else{
                // for(auto v : level[i+1]){
                //     dp[x] = (dp[x] + dp[v]) % mod;
                // }
                dp[x] = prev;
                if(i != 0){
                    for(auto v : G[x]){
                        dp[x] = (((dp[x] - dp[v]) % mod) + mod) % mod;
                    }
                }
                dp[x] = (dp[x] + 1) % mod;
            }
            temp = (temp + dp[x]) % mod;
            // cout << x << " " << dp[x] << " ";
        }
        prev = temp;
    }
    cout << dp[1] << "\n";
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
// https://codeforces.com/contest/2070/problem/D