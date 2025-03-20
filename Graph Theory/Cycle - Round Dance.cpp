#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <int> G[N];
vector <bool> visited;

bool dfs(int u, int par = -1){
    visited[u] = true;
    for(auto v : G[u]){
        if(visited[v] == true && v != par) return true;
        if(!visited[v] && dfs(v, u)) return true; // cycle check
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n+1);
    set <pair<int,int>> st;
    for(int i = 1; i <= n; i++) G[i].clear();
    visited.assign(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        int a = min(i, v[i]), b = max(i, v[i]);
        if(st.count({a,b})) continue;
        st.insert({a,b});
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll mini = 0, maxi = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            maxi++;
            mini += dfs(i);
        }
    }
    mini = min(maxi, mini+1);
    cout << max(mini, 1ll) << " " << maxi << "\n";
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
// https://codeforces.com/problemset/problem/1833/E