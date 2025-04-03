#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 2e5 + 7;

vector <int> G[N];
vector <ll> comp, name, ischeck, visited;
int c;

void dfs(int u){
    visited[u] = true;
    stack <int> st;
    vector <int> vv;
    int ans = 1;
    st.push(u);
    vv.push_back(u);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        for(auto v : G[u]){
            if(!visited[v]){
                st.push(v);
                vv.push_back(v);
                visited[v] = true;
                ans++;
            }
        }
    }
    for(auto x : vv){
        comp[x] = ans;
        name[x] = c;
    }
    c++;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        G[i].push_back(a);
    }
    visited.assign(n+1, 0);
    comp.assign(n+1, 0);
    name.assign(n+1, 0);
    ischeck.assign(n+1, 0);
    c = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    ll ans = 0;
    vector <ll> ansv;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(!ischeck[name[a]]){
            ans += comp[a];
            ischeck[name[a]] = 1;
        }
        ansv.push_back(ans);
    }
    for(auto x : ansv){
        cout << x << " ";
    }
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
// https://codeforces.com/contest/2086/problem/C