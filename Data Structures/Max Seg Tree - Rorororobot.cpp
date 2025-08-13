#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

ll arr[N];
struct Node {
    ll maxi;
    Node() : maxi(0) {}
    Node(ll val) : maxi(val) {}
};

struct SegmentTree {
    vector<Node> tree;
    ll n;
    SegmentTree(ll size) {
        n = size;
        tree.resize(4 * size, Node());
    }
    Node combine(const Node& left, const Node& right) {
        if (left.maxi == 0) return right;
        if (right.maxi == 0) return left;
        Node parent;
        parent.maxi = max(left.maxi, right.maxi);
        return parent;
    }
    void build(ll nodeIndex, ll start, ll end) {
        if(start == end) {
            tree[nodeIndex] = Node(arr[start]);
            return;
        }
        ll mid = (start + end) >> 1;
        ll leftChild = nodeIndex << 1; // 2 * nodeIndex
        ll rightChild = leftChild | 1; // 2 * nodeIndex + 1
        build(leftChild, start, mid);
        build(rightChild, mid + 1, end);
        tree[nodeIndex] = combine(tree[leftChild], tree[rightChild]);
    }
    void update(ll nodeIndex, ll start, ll end, ll updateIndex, ll newValue) {
        if(start == end) {
            tree[nodeIndex] = Node(newValue);
            return;
        }
        ll mid = (start + end) >> 1;
        ll leftChild = nodeIndex << 1;
        ll rightChild = leftChild | 1;
        if(updateIndex <= mid) update(leftChild, start, mid, updateIndex, newValue);
        else update(rightChild, mid + 1, end, updateIndex, newValue);
        tree[nodeIndex] = combine(tree[leftChild], tree[rightChild]);
    }
    Node query(ll nodeIndex, ll start, ll end, ll L, ll R) {
        if (R < start || end < L) return Node();
        if (L <= start && end <= R) return tree[nodeIndex];
        ll mid = (start + end) >> 1;
        ll leftChild = nodeIndex << 1;
        ll rightChild = leftChild | 1;
        Node leftResult = query(leftChild, start, mid, L, R);
        Node rightResult = query(rightChild, mid + 1, end, L, R);
        return combine(leftResult, rightResult);
    }
    ll get(ll l, ll r){
        Node p = query(1, 0, n-1, l, r); // 0-based
        return p.maxi;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) cin >> arr[i];
    SegmentTree segTree(m);
    segTree.build(1, 0, m - 1);
    ll q; cin >> q;
    while(q--) {
        ll sx, sy, fx, fy, k;
        cin >> sx >> sy >> fx >> fy >> k;
        sy--, fy--;
        if(fy < sy){
            swap(sx, fx);
            swap(sy, fy);
        }
        ll dx = abs(fx - sx);
        ll dy = abs(fy - sy);
        if(dx % k != 0 || dy % k != 0 || sx <= arr[sy] || fx <= arr[fy]){
            cout << "NO\n";
            continue;
        }
        ll maxi = segTree.get(sy, fy);
        ll up = abs(maxi - sx) / k +  1;
        if(maxi < sx) up = 0;
        // cout << sx << " " << arr[sy] << " -> " << maxi << " " << up << " : ";
        if(sx + up * k <= n) cout << "YES\n";
        else cout << "NO\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1709/problem/D