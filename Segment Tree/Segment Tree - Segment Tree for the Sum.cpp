#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5 + 7;

ll arr[N];
struct SegmentTree {
    ll tree[4 * N];
    SegmentTree() { 
        memset(tree, 0, sizeof tree);
    }
    void build(ll nodeIndex, ll start, ll end) {
        if(start == end) {
            tree[nodeIndex] = arr[start];
            return;
        }
        ll mid = (start + end) >> 1;
        ll leftChild = nodeIndex << 1; // 2i
        ll rightChild = leftChild | 1; // 2i + 1
        build(leftChild, start, mid);
        build(rightChild, mid + 1, end);
        tree[nodeIndex] = tree[leftChild] + tree[rightChild];
    }
    void update(ll nodeIndex, ll start, ll end, ll updateIndex, ll newValue) {
        if(start > updateIndex || end < updateIndex) return;
        if(start == end && start == updateIndex) {
            tree[nodeIndex] = newValue;
            return;
        }
        ll mid = (start + end) >> 1;
        ll leftChild = nodeIndex << 1;
        ll rightChild = leftChild | 1;
        update(leftChild, start, mid, updateIndex, newValue);
        update(rightChild, mid + 1, end, updateIndex, newValue);
        tree[nodeIndex] = tree[leftChild] + tree[rightChild];
    }
    ll query(ll nodeIndex, ll start, ll end, ll left, ll right) {
        if (start > right || end < left) return 0;
        if (start >= left && end <= right) return tree[nodeIndex];
        ll mid = (start + end) >> 1;
        ll leftChild = nodeIndex << 1;
        ll rightChild = leftChild | 1;
        ll leftSum = query(leftChild, start, mid, left, right);
        ll rightSum = query(rightChild, mid + 1, end, left, right);
        return leftSum + rightSum;
    }
} segTree;

void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    segTree.build(1, 0, n - 1);
    while(m--) {
        int type;
        cin >> type;
        if(type == 1){
            ll index, value;
            cin >> index >> value;
            segTree.update(1, 0, n - 1, index, value);
        } 
        else if(type == 2){
            ll left, right;
            cin >> left >> right;
            cout << segTree.query(1, 0, n - 1, left, right - 1) << '\n';
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
// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A