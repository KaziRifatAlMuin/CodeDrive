#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7, mod = 1e9 + 7;

ll pow2[N];
vector <vector<int>> G;

ll base, L, R;
vector <bool> isbase;

void dfs(int u, int par = -1){
    base++;
    isbase[u] = true;
    if(G[u].size() > 2) return;
    for(auto v : G[u]){
        if(v == par) continue;
        dfs(v, u);
    }
}

int dfs2(int u, int par = -1){
    int len = 1;
    for(auto v : G[u]){
        if(v == par || isbase[v]) continue;
        len += dfs2(v, u);
    }
    return len;
}

void pre() {
    pow2[0] = 1;
    for(int i = 1; i < N; i++) pow2[i] = (pow2[i-1] * 2) % mod;
}

void solve(){
    int n;
    cin >> n;
    G.assign(n+1, {});
    isbase.assign(n+1, false);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int one = 0, branch = 1;
    for(int i = 2; i <= n; i++){
        if(G[i].size() == 1) one++;
        if(G[i].size() == 3) branch = i;
    }
    if(one == 1) cout << pow2[n] << "\n";
    else if(one > 2) cout << 0 << "\n";
    else{
        ll ans = 0;
        base = 0, L = 0, R = 0;
        vector <int> childsize;
        if(branch != 1) dfs(1);
        else isbase[1] = true, base++;
        for(auto x : G[branch]){
            if(!isbase[x]){
                childsize.push_back(dfs2(x));
            }
        }
        if(childsize.size() >= 2) L = childsize[0], R = childsize[1];
        // cout << base << " " << L << " " << R << "\n";
        ans = (ans + pow2[abs(L - R)]) % mod;
        if(abs(L - R) > 0) ans = (ans + pow2[abs(L - R) - 1]) % mod;
        else ans++;
        ans = (ans * pow2[base]) % mod;
        cout << ans << "\n";
    }
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
// https://codeforces.com/contest/2117/problem/F