#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 5;

vector <int> G[N];
vector <ll> tin, tout;
int t;

void dfs(int u, int par = -1){
    tin[u] = ++t; // Euler Tour
    for(auto v : G[u]){
        if(v != par){
            dfs(v, u);
        }
    }
    tout[u] = t;
}

struct node {
    ll val;
};

struct SegmentTree {
    vector<node> tree;
    SegmentTree(ll n)
    {
        tree.resize(4 * n);
    }

    node combine(const node &left, const node &right) {
        node parent;
        parent.val = left.val + right.val;
        return parent;
    }

    void build(int ind, int low, int high) {
        if(low == high) {
            tree[ind].val = 0;
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        tree[ind] = combine(tree[2 * ind + 1], tree[2 * ind + 2]);
    }
    
    void update(int ind, int low, int high, int ix, ll x) {
        if(low == high) {
            tree[ind].val = x;
            return;
        }
        int mid = (low + high) / 2;
        if (ix <= mid) update(2 * ind + 1, low, mid, ix, x);
        else update(2 * ind + 2, mid + 1, high, ix, x);
        tree[ind] = combine(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    node query(ll ind, ll low, ll high, ll L, ll R) {
        if(R < low || high < L) return node();
        if(L <= low && high <= R) return tree[ind];
        ll mid = (low + high) / 2;
        node leftResult = query(2 * ind + 1, low, mid, L, R);
        node rightResult = query(2 * ind + 2, mid + 1, high, L, R);
        return combine(leftResult, rightResult);
    }

    ll getans(ll ind, ll low, ll high, ll L, ll R){
        node ans = query(ind, low, high, L, R);
        return ans.val;
    }
};

void solve(){
    int n;
    cin >> n;
    tin.assign(n+1,0);
    tout.assign(n+1,0);
    for(int i = 0; i <= n; i++) G[i].clear();
    vector <vector<int>> nodes(n+1);
    for(int i = 1; i <= n; i++) {
        int w; cin >> w;
        nodes[w].push_back(i);
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    t = 0;
    dfs(1);
    ll sum = 0;
    SegmentTree seg(n+1);
    seg.build(0,0,n);

    for(int val = n; val > 0; val--){
        for(auto i : nodes[val]){
            if(seg.getans(0,0,n,tin[i],tout[i]) != sum){
                cout << i << "\n";
                return;
            }
        }
        for(auto i : nodes[val]){
            seg.update(0,0,n,tin[i],1);
            sum++;
        }
    }
    cout << 0 << "\n";
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
// https://codeforces.com/contest/2062/problem/E1