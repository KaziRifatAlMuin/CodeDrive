#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node {
    ll pmax, pmin, smax, smin, ans;
};

struct SegmentTree {
    vector<node> tree;
    SegmentTree(ll n)
    {
        tree.resize(4 * n);
    }

    node combine(const node &left, const node &right) {
        node parent;
        parent.pmax = max(left.pmax, right.pmax);
        parent.pmin = min(left.pmin, right.pmin);
        parent.smax = max(left.smax, right.smax);
        parent.smin = min(left.smin, right.smin);
        parent.ans = max({left.ans, right.ans, left.pmax - right.pmin, right.smax - left.smin}); // Most Important Line
        return parent;
    }

    void build(int ind, int low, int high, const vector<ll> &v) {
        if (low == high) {
            tree[ind].pmax = v[low] + (low + 1);
            tree[ind].pmin = v[low] + (low + 1);
            tree[ind].smax = v[low] - (low + 1);
            tree[ind].smin = v[low] - (low + 1);
            tree[ind].ans = 0;
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);
        tree[ind] = combine(tree[2 * ind + 1], tree[2 * ind + 2]);
    }
    
    void update(int ind, int low, int high, int ix, ll x) {
        if (low == high) {
            tree[ind].pmax = x + (low + 1);
            tree[ind].pmin = x + (low + 1);
            tree[ind].smax = x - (low + 1);
            tree[ind].smin = x - (low + 1);
            tree[ind].ans = 0;
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

    ll getans() {
        return tree[0].ans;
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    SegmentTree seg(n);
    seg.build(0, 0, n - 1, v);
    cout << seg.getans() << "\n";
    
    while (q--) {
        int ix; ll x;
        cin >> ix >> x;
        ix--;
        seg.update(0, 0, n - 1, ix, x);
        cout << seg.getans() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// https://codeforces.com/problemset/problem/2057/D