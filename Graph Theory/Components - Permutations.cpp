#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1007;

vector <int> G[N];
bool visited[N];

int dfs(int u){
    visited[u] = true;
    stack <int> st;
    int ans = 1;
    st.push(u);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        for(auto v : G[u]){
            if(!visited[v]){
                st.push(v);
                visited[v] = true;
                ans++;
            }
        }
    }
    return ans;
}

inline ll lcm(ll a, ll b) {
    return (a / __gcd(a,b)) * b;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        G[i].push_back(a);
    }
    vector <ll> components;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            components.push_back(dfs(i));
        }
    }
    ll ans = components[0];
    for(int i = 1; i < components.size(); i++){
        ans = lcm(ans, components[i]);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://acm.timus.ru/problem.aspx?space=1&num=1024