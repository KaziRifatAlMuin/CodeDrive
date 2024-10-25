#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll INF = LLONG_MIN;
const int N = 50000;

ll arr[N];
struct Node {
    ll sum, prefixSum, suffixSum, maxSum;
    Node() : sum(0), prefixSum(INF), suffixSum(INF), maxSum(INF) {}
    Node(ll val) : sum(val), prefixSum(val), suffixSum(val), maxSum(val) {}
};

struct SegmentTree {
    vector<Node> tree;
    SegmentTree(int size) {
        tree.resize(4 * size, Node());
    }
    Node combine(const Node& left, const Node& right) {
        if (left.maxSum == INF) return right;
        if (right.maxSum == INF) return left;
        Node parent;
        parent.sum = left.sum + right.sum;
        parent.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
        parent.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);
        parent.maxSum = max({left.maxSum, right.maxSum, left.suffixSum + right.prefixSum});
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
};

void solve() {
    ll n, m;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
    SegmentTree segTree(n);
    segTree.build(1, 0, n - 1);
    while(m--) {
        int type;
        cin >> type;
        if(type == 0){
            ll index, value;
            cin >> index >> value;
            index--;
            segTree.update(1, 0, n - 1, index, value);
        } 
        else if(type == 1){
            ll left, right;
            cin >> left >> right;
            left--; right--;
            Node res = segTree.query(1, 0, n - 1, left, right);
            cout << res.maxSum << '\n';
        }
    }
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
// https://www.spoj.com/problems/GSS3/en/